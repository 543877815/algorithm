// 广度优先搜索，超时
// 空间复杂度：O(n^2)
// 时间复杂度：O(n^4?)
class Solution {
public:
    int n, m;
    int dp[4][2] = {
            {0,  1},
            {0,  -1},
            {1,  0},
            {-1, 0}
    };
    vector <vector<int>> res;
    vector <vector<bool>> visited;
    int MAX = 20000;

    bool isArea(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(vector <vector<int>> &matrix, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int newx = x + dp[i][0];
            int newy = y + dp[i][1];
            if (isArea(newx, newy) && matrix[newx][newy] != 0 && !visited[newx][newy]) {
                if (matrix[newx][newy] == 0) res[newx][newy] = 0;
                else res[newx][newy] = min(res[newx][newy], res[x][y] + 1);
                visited[newx][newy] = true;
                dfs(matrix, newx, newy);
                visited[newx][newy] = false;
            }
        }
    }

    vector <vector<int>> updateMatrix(vector <vector<int>> &matrix) {
        n = matrix.size();
        if (n == 0) return matrix;
        m = matrix[0].size();
        if (m == 0) return matrix;
        res = vector < vector < int >> (n, vector<int>(m, MAX));
        visited = vector < vector < bool >> (n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0 && res[i][j] == MAX) {
                    res[i][j] = 0;
                    visited[i][j] = true;
                    dfs(matrix, i, j);
                }
            }
        }

        return res;
    }
};


// 广度优先搜索，栈
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
public:
    int n, m;
    int dp[4][2] = {
            {0,  1},
            {0,  -1},
            {1,  0},
            {-1, 0}
    };
    vector <vector<int>> res;
    vector <vector<bool>> visited;
    queue <pair<int, int>> q;

    bool isArea(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    vector <vector<int>> updateMatrix(vector <vector<int>> &matrix) {
        n = matrix.size();
        if (n == 0) return matrix;
        m = matrix[0].size();
        if (m == 0) return matrix;
        res = vector < vector < int >> (n, vector<int>(m, 0));
        visited = vector < vector < bool >> (n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    visited[i][j] = true;
                }
            }
        }
        while (!q.empty()) {
            auto[x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x + dp[i][0];
                int newy = y + dp[i][1];
                if (isArea(newx, newy) && !visited[newx][newy]) {
                    res[newx][newy] = res[x][y] + 1;
                    q.emplace(newx, newy);
                    visited[newx][newy] = 1;
                }
            }
        }
        return res;
    }
};


// 动态规划
// 时间复杂度：O(4n^2)
// 空间复杂度：O(1)
class Solution {
public:
    int dp[4][2] = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1}
    };
    int n, m;

    bool isArea(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    vector <vector<int>> updateMatrix(vector <vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector <vector<int>> res = vector < vector < int >> (n, vector<int>(m, 20000));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) res[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) res[i][j] = min(res[i][j], res[i - 1][j] + 1);
                if (j > 0) res[i][j] = min(res[i][j], res[i][j - 1] + 1);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (i > 0) res[i][j] = min(res[i][j], res[i - 1][j] + 1);
                if (j < m - 1) res[i][j] = min(res[i][j], res[i][j + 1] + 1);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (i < n - 1) res[i][j] = min(res[i][j], res[i + 1][j] + 1);
                if (j > 0) res[i][j] = min(res[i][j], res[i][j - 1] + 1);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i < n - 1) res[i][j] = min(res[i][j], res[i + 1][j] + 1);
                if (j < m - 1) res[i][j] = min(res[i][j], res[i][j + 1] + 1);
            }
        }

        return res;
    }
};


// 动态规划，常数优化
// 时间复杂度：O(2n^2)
// 空间复杂度：O(1)
class Solution {
public:
    int dp[4][2] = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1}
    };
    int n, m;

    bool isArea(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    vector <vector<int>> updateMatrix(vector <vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector <vector<int>> res = vector < vector < int >> (n, vector<int>(m, 20000));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) res[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) res[i][j] = min(res[i][j], res[i - 1][j] + 1);
                if (j > 0) res[i][j] = min(res[i][j], res[i][j - 1] + 1);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i < n - 1) res[i][j] = min(res[i][j], res[i + 1][j] + 1);
                if (j < m - 1) res[i][j] = min(res[i][j], res[i][j + 1] + 1);
            }
        }

        return res;
    }
};