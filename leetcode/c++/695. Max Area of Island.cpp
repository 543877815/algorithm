// DFS
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
private:
    int m, n, max_area;
    vector <vector<bool>> visited;
    int dp[4][2] = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1}
    };

    bool isArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void DFS(vector <vector<int>> &grid, int row, int col, int &area) {
        if (row == 3 && col == 8)
            int a = 1;
        visited[row][col] = true;
        if (grid[row][col] == 1) {
            area++;
            max_area = max(max_area, area);
            for (int i = 0; i < 4; i++) {
                int newx = row + dp[i][0];
                int newy = col + dp[i][1];
                if (isArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == 1) {
                    DFS(grid, newx, newy, area);
                }
            }
        }
    }

public:
    int maxAreaOfIsland(vector <vector<int>> &grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        if (n == 0) return 0;
        visited = vector < vector < bool >> (m, vector<bool>(n, false));
        max_area = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int area = 0;
                    DFS(grid, i, j, area);
                }
            }
        }
        return max_area;
    }
};