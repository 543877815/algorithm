// 动态规划
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
/*
 * 替换/跳过  删除
 *   插入    “  ”
 *
 */
class Solution {
public:
    /**
     * min edit cost
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @param ic int整型 insert cost
     * @param dc int整型 delete cost
     * @param rc int整型 replace cost
     * @return int整型
     */
    int minEditCost(string str1, string str2, int ic, int dc, int rc) {
        // write code here
        int n = str1.size(), m = str2.size();
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = i * dc;
        }

        for (int j = 1; j <= m; j++) {
            dp[0][j] = j * ic;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + dc, min(dp[i][j - 1] + ic, dp[i - 1][j - 1] + rc));
                }
            }
        }

        return dp[n][m];
    }
};