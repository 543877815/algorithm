// 深度优先搜索
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>>
     * @return int整型
     */
    const int dp[4][2]{
            {0,  1},
            {0,  -1},
            {-1, 0},
            {1,  0}
    };

    bool isArea(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    int dfs(int x, int y, vector <vector<char>> &grid, vector <vector<bool>> &used) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[x][y] == '0') return 0;

        for (int i = 0; i < 4; i++) {
            int new_x = x + dp[i][0];
            int new_y = y + dp[i][1];
            if (isArea(new_x, new_y, n, m) && !used[new_x][new_y] && grid[new_x][new_y] == '1') {
                used[new_x][new_y] = true;
                dfs(new_x, new_y, grid, used);
            }
        }

        return grid[x][y] == '1';
    }

    int solve(vector <vector<char>> &grid) {
        // write code here
        int res = 0;
        int n = grid.size();
        if (n == 0) return res;
        int m = grid[0].size();
        if (m == 0) return res;
        vector <vector<bool>> used = vector < vector < bool >> (n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!used[i][j]) {
                    res += dfs(i, j, grid, used);
                }
            }
        }
        return res;
    }
};