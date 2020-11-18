// 直接排序
// 时间复杂度：O(nmlognm)
// 空间复杂度：O(lognm)
class Solution {
public:
    vector <vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector <vector<int>> res;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                res.push_back({i, j});
            }
        }
        sort(res.begin(), res.end(), [&](vector<int> &x, vector<int> &y) {
            return (abs(x[0] - r0) + abs(x[1] - c0)) < (abs(y[0] - r0) + abs(y[1] - c0));
        });

        return res;
    }
};

// 桶排序
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    int dist(int x0, int y0, int x1, int y1) {
        return abs(x0 - x1) + abs(y0 - y1);
    }

    vector <vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int maxDist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
        vector < vector < vector < int >> > bucket(maxDist + 1);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                bucket[dist(i, j, r0, c0)].push_back({i, j});
            }
        }

        vector <vector<int>> res;
        for (int i = 0; i < bucket.size(); i++) {
            for (int j = 0; j < bucket[i].size(); j++) {
                res.push_back(bucket[i][j]);
            }
        }

        return res;
    }
};


// 广度优先遍历
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
private:
    int m, n;
    int dp[4][2] = {
            {-1, 0},
            {0,  -1},
            {0,  1},
            {1,  0}
    };
    queue <pair<int, int>> q;

    bool isArea(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

public:
    vector <vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector <vector<int>> res;
        vector <vector<bool>> visited = vector < vector < bool >> (R, vector<bool>(C, false));
        res.push_back({r0, c0});
        visited[r0][c0] = true;
        m = R;
        n = C;
        q.push({r0, c0});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x + dp[i][0];
                int newy = y + dp[i][1];
                if (isArea(newx, newy) && !visited[newx][newy]) {
                    q.push({newx, newy});
                    visited[newx][newy] = true;
                    res.push_back({newx, newy});
                }
            }
        }
        return res;
    }
};