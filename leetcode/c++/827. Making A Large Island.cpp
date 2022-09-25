// 广度优先搜索
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)

class Solution {
public:
    int dp[4][2] = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0}
    };

    bool isArea(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    int bfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y, int idx) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int res = 0;
        q.push(make_pair(x, y));
        visited[x][y] = idx;
        while (!q.empty()) {
            res++;
            auto [curr_x, curr_y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_x = curr_x + dp[i][0];
                int new_y = curr_y + dp[i][1];
                if (isArea(new_x, new_y, n, m) && visited[new_x][new_y] == -1 && grid[new_x][new_y] == 1) {
                    visited[new_x][new_y] = idx;
                    q.push(make_pair(new_x, new_y));
                }
            }
        }
        return res;
    }

    int largestIsland(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int idx = -1;
        int res = 0;
        vector<vector<int>> visited(n, vector<int>(m, idx));
        unordered_map<int, int> area;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == -1 && grid[i][j] == 1) {
                    idx++;
                    area[idx] = bfs(grid, visited, i, j, idx);
                    res = max(res, area[idx]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    int tmp = 1;
                    unordered_map<int, bool> used;
                    for (int k = 0; k < 4; k++) {
                        int new_x = i + dp[k][0];
                        int new_y = j + dp[k][1];
                        if (isArea(new_x, new_y, n, m) && area.count(visited[new_x][new_y])) {
                            if (!used.count(visited[new_x][new_y])) {
                                tmp += area[visited[new_x][new_y]];
                                used[visited[new_x][new_y]] = true;
                            }
                        }
                    }
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
};