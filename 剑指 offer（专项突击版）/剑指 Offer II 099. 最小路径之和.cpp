// 动态规划
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    /**
     *
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        vector<vector<int>>dp(n, vector<int>(m, 0));
        dp[0][0] = matrix[0][0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i-1][0] + matrix[i][0];
        }

        for (int j = 1; j < m; j++) {
            dp[0][j] = dp[0][j-1] + matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + matrix[i][j];
            }
        }

        return dp[n-1][m-1];
    }
};