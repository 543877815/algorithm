// 通过是否阻塞来建模
// 用 set 来定义是否访问
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
// n 表示 blocked 的长度
class Solution {
public:
    static constexpr int BLOCKED = -1;
    static constexpr int VALID = 0;
    static constexpr int FOUND = 1;

    static constexpr int dp[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
    };

    static constexpr int BOUNDARY = 1000000;

    bool isArea(int x, int y) {
        return x >= 0 && y >= 0 && x < BOUNDARY && y < BOUNDARY;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int n = blocked.size();
        if (n < 2) return true;
        // 定义哈希规则
        auto hash_fn = [fn = hash<long long>()](const pair<int, int>& o) -> size_t {
            auto& [x, y] = o;
            return fn((long long)x << 20 | y);
        };
        unordered_set<pair<int, int>, decltype(hash_fn)> hash_blocked(0, hash_fn);

        for (const auto& pos: blocked) {
            hash_blocked.emplace(pos[0], pos[1]);
        }

        auto check = [&](vector<int> & start, vector<int> finish) -> int {
            int sx = start[0], sy = start[1];
            int fx = finish[0], fy = finish[1];
            int countdown = n * (n - 1) / 2;
            queue<pair<int, int>> q;
            q.emplace(sx, sy);
            unordered_set<pair<int, int>, decltype(hash_fn)> visited(0, hash_fn);
            visited.emplace(sx, sy);
            while (!q.empty() && countdown > 0) {
                auto[x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dp[i][0], ny = y + dp[i][1];
                    if (isArea(nx, ny) && !visited.count({nx, ny}) && !hash_blocked.count({nx, ny})) {
                        if (nx == fx && ny == fy) return FOUND;
                        countdown--;
                        q.emplace(nx, ny);
                        visited.emplace(nx, ny);
                    }
                }
            }
            if (countdown > 0) return BLOCKED;
            return VALID;
        };

        int s2t = check(source, target);
        int t2s = check(target, source);
        if (s2t == FOUND) {
            return true;
        } else if (s2t == BLOCKED || t2s == BLOCKED) {
            return false;
        } else {
            return true;
        }
    }
};

// 通过传统广度优先搜索来建模，但是要对坐标进行离散化
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
// n 表示 blocked 的长度

class Solution {
public:
    static constexpr int BOUNDARY = 1000000;
    static constexpr int dp[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
    };

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int n = blocked.size();
        if (n < 2) return true;

        vector<int> rows, columns;
        for (const auto &pos : blocked) {
            rows.push_back(pos[0]);
            columns.push_back(pos[1]);
        }

        rows.push_back(source[0]);
        rows.push_back(target[0]);
        columns.push_back(source[1]);
        columns.push_back(target[1]);

        // 离散化
        sort(rows.begin(), rows.end());
        sort(columns.begin(), columns.end());
        rows.erase(unique(rows.begin(), rows.end()), rows.end());
        columns.erase(unique(columns.begin(), columns.end()), columns.end());
        unordered_map<int, int> r_mapping, c_mapping;

        int r_id = (rows[0] == 0 ? 0 : 1);
        r_mapping[rows[0]] = r_id;
        for (int i = 1; i < rows.size(); i++) {
            r_id += (rows[i] == rows[i-1] + 1 ? 1 : 2);
            r_mapping[rows[i]] = r_id;
        }
        if (rows.back() != BOUNDARY - 1) r_id++;

        int c_id = (columns[0] == 0 ? 0 : 1);
        c_mapping[columns[0]] = c_id;
        for (int i = 1; i < columns.size(); i++) {
            c_id += (columns[i] == columns[i-1] + 1 ? 1 : 2);
            c_mapping[columns[i]] = c_id;
        }
        if (columns.back() != BOUNDARY - 1) c_id++;

        vector<vector<bool>>visited = vector<vector<bool>>(r_id+1, vector<bool>(c_id+1, false));
        for (const auto&pos : blocked) {
            int x = pos[0], y = pos[1];
            visited[r_mapping[x]][c_mapping[y]] = true;
        }

        int sx = r_mapping[source[0]], sy = c_mapping[source[1]];
        int tx = r_mapping[target[0]], ty = c_mapping[target[1]];

        queue<pair<int, int>>q;
        q.emplace(sx, sy);
        visited[sx][sy] = true;

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_x = x + dp[i][0], new_y = y + dp[i][1];
                if (new_x >= 0 && new_y >= 0 && new_x <= r_id && new_y <= c_id && !visited[new_x][new_y]) {
                    if (new_x == tx && new_y == ty) return true;
                    q.emplace(new_x, new_y);
                    visited[new_x][new_y] = true;
                }
            }
        }
        return false;
    }
};