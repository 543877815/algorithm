// 动态规划
// 时间复杂度：O(n^3)
// 空间复杂度：O(n^2)
class Solution {
public:
    int strangePrinter(string s) {
        // dp[i][j] 表示完成序列 s[i] 到 s[j] 所需最少的打印次数
        int n = s.size();
        vector <vector<int>> dp = vector < vector < int >> (n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    int min_num = INT_MAX;
                    for (int k = i; k < j; k++) {
                        min_num = min(min_num, dp[i][k] + dp[k + 1][j]);
                    }
                    dp[i][j] = min_num;
                }
            }
        }
        return dp[0][n - 1];
    }
};