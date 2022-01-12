// 深度优先搜索
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    int dp[4][2] = {
            {1,  0},
            {-1, 0},
            {0,  -1},
            {0,  1}
    };

    bool isArea(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    void dfs(vector <vector<int>> &grid, vector <vector<int>> &mark, int currRow, int currCol, int color) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        for (int i = 0; i < 4; i++) {
            int newRow = currRow + dp[i][0];
            int newCol = currCol + dp[i][1];
            if (isArea(newRow, newCol, n, m) && grid[newRow][newCol] == color) {
                count++;
                if (!mark[newRow][newCol]) {
                    mark[newRow][newCol] = 1;
                    dfs(grid, mark, newRow, newCol, color);
                }
            }
        }
        if (grid[currRow][currCol] == color && count < 4) {
            mark[currRow][currCol] = 2;
        }

    }


    vector <vector<int>> colorBorder(vector <vector<int>> &grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        vector <vector<int>> mark = vector < vector < int >> (n, vector<int>(m, 0));
        mark[row][col] = 1;

        dfs(grid, mark, row, col, grid[row][col]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mark[i][j] == 2) grid[i][j] = color;
            }
        }
        return grid;
    }
};