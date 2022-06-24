class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), p = s3.size();
        if (n + m != p) return false;

        // dp[i][j] 表示s1前i个字符和s2前j个字符能否与s3前i+j个字符匹配
        vector <vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] & (s1[i - 1] == s3[i - 1]);
        }

        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j - 1] & (s2[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i][j] | (dp[i - 1][j] & (s3[i + j - 1] == s1[i - 1]));
                dp[i][j] = dp[i][j] | (dp[i][j - 1] & (s3[i + j - 1] == s2[j - 1]));
            }
        }

        return dp[n][m];
    }
};