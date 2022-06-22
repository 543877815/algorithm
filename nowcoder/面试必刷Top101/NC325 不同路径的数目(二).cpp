// 动态规划
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    int uniquePathsWithObstacles(vector <vector<int>> &obstacleGrid) {
        // write code here
        int n = obstacleGrid.size();
        if (n == 0) return 0;
        int m = obstacleGrid[0].size();
        if (m == 0) return 0;
        vector <vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = obstacleGrid[0][0] == 1;
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0];
            if (!obstacleGrid[i][0]) dp[i][0] = 0;
        }

        for (int j = 1; j < m; j++) {
            dp[0][j] = dp[0][j - 1];
            if (!obstacleGrid[0][j]) dp[0][j] = 0;
        }


        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                if (!obstacleGrid[i][j]) dp[i][j] = 0;
            }
        }

        return dp[n - 1][m - 1];
    }
};