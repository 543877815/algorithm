// 动态规划
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n < m) return 0;
        // dp[i][j] 表示s[i:]的子序列中t[j:]出现的个数
        vector <vector<long>> dp(n + 1, vector<long>(m + 1));
        // 空字符匹配数初始化为1
        for (int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    // 上个阶段对该字符没匹配的和上个阶段对该字符匹配的
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    // 上个阶段对该字符匹配的
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};