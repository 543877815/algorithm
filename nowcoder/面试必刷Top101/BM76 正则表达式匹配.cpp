// 动态规划
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @param pattern string字符串
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        // write code here
        str = " " + str;
        pattern = " " + pattern;
        int n = str.size(), m = pattern.size();
        // dp[i][j] 表示 s前i个字符和p前j个字符的匹配情况
        vector <vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pattern[j - 1] != '*') { // 如果不是通配符
                    if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.') { // 如果兩字段相同或者是任意字符，處理aa, aa和aa, a.
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else { // 如果上一個是通配符
                    if (str[i - 1] != pattern[j - 2] && pattern[j - 2] != '.') { // 如果不是aa, .*和aa, ab*，則認爲匹配[i][j-2]
                        dp[i][j] = dp[i][j - 2];
                    } else {
                        dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j]; // 如果是.*，則可任意匹配
                    }
                }
            }
        }


        return dp[n][m];
    }
};