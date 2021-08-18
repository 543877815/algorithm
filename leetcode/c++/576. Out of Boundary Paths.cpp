// 广度优先搜索(超时)
// 时间复杂度：O(2^n)
// 空间复杂度：O(n+m)
class Solution {
public:
    int res = 0;
    const int dp[4][2] = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1}
    };

    bool isArea(int m, int n, int x, int y) {
        return x < m && y < n && x >= 0 && y >= 0;
    }

    void bfs(int m, int n, int curr_m, int curr_n, int move) {
        if (move == 0) return;
        for (int i = 0; i < 4; i++) {
            int new_m = curr_m + dp[i][0];
            int new_n = curr_n + dp[i][1];
            if (isArea(m, n, new_m, new_n)) {
                if (move > 0) bfs(m, n, new_m, new_n, move - 1);
            } else {
                res++;
            }
        }
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        bfs(m, n, startRow, startColumn, maxMove);
        return res;
    }
};

// 动态规划, dp[i][x][y] 表示第 i 步，格子(x,y)上的棋子个数
// 时间复杂度：O(maxMove * n * m)
// 空间复杂度：O(maxMove * n * m)
class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    bool isArea(int m, int n, int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector < vector < vector < int>>> dp = vector < vector < vector < int>>>(maxMove + 1,
                vector < vector < int >> (m, vector<int>(n, 0)));
        int directions[4][2] = {
                {1,  0},
                {-1, 0},
                {0,  1},
                {0,  -1}
        };
        dp[0][startRow][startColumn] = 1;
        int res = 0;
        for (int i = 0; i < maxMove; i++) {
            vector <vector<int>> tmp = vector < vector < int >> (m, vector<int>(n, 0));
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    for (int j = 0; j < 4; j++) {
                        int new_x = x + directions[j][0];
                        int new_y = y + directions[j][1];
                        if (isArea(m, n, new_x, new_y)) {
                            tmp[new_x][new_y] = (tmp[new_x][new_y] + dp[i][x][y]) % MOD;;
                        } else {
                            res = (dp[i][x][y] + res) % MOD;;
                        }
                    }
                }
            }
            dp[i + 1] = tmp;
        }
        return res;
    }
};


// 动态规划空间优化
// 时间复杂度：O(maxMove * n * m)
// 空间复杂度：O(nm)
class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    bool isArea(int m, int n, int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector <vector<int>> pre = vector < vector < int >> (m, vector<int>(n, 0));
        int directions[4][2] = {
                {1,  0},
                {-1, 0},
                {0,  1},
                {0,  -1}
        };
        pre[startRow][startColumn] = 1;
        int res = 0;
        for (int i = 0; i < maxMove; i++) {
            vector <vector<int>> curr = vector < vector < int >> (m, vector<int>(n, 0));
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    for (int j = 0; j < 4; j++) {
                        int new_x = x + directions[j][0];
                        int new_y = y + directions[j][1];
                        if (isArea(m, n, new_x, new_y)) {
                            curr[new_x][new_y] = (curr[new_x][new_y] + pre[x][y]) % MOD;;
                        } else {
                            res = (pre[x][y] + res) % MOD;;
                        }
                    }
                }
            }
            pre = curr;
        }
        return res;
    }
};