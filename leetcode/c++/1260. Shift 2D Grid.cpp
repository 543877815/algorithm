// 时间复杂度：O(knm)
// 空间复杂度：O(n)
class Solution {
public:
    vector <vector<int>> shiftGrid(vector <vector<int>> &grid, int k) {
        vector <vector<int>> res;
        int m = grid.size();
        if (m == 0) return res;
        int n = grid[0].size();
        for (int i = 0; i < k; i++) {
            vector<int> tmp(m);
            for (int i = 0; i < m; i++) {
                tmp[i] = grid[i][n - 1];
            }
            for (int i = 0; i < m; i++) {
                for (int j = n - 1; j > 0; j--) {
                    grid[i][j] = grid[i][j - 1];
                }
            }

            for (int i = 1; i < m; i++) {
                grid[i][0] = tmp[i - 1];
            }
            grid[0][0] = tmp[m - 1];
        }

        return grid;
    }
};
