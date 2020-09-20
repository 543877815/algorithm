// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
                class Solution {
                public:
                    int minPathSum(vector <vector<int>> &grid) {
                        int n = grid.size();
                        int m = grid[0].size();
                        vector <vector<int>> dp = vector < vector < int >> (n, vector<int>(m, INT_MAX));
                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < m; j++) {
                                if (i == 0 && j == 0) dp[i][j] = grid[i][j];
                else if (i == 0 && j != 0) dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if (i != 0 && j == 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
                else dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
        return dp[n - 1][m - 1];
    }
};