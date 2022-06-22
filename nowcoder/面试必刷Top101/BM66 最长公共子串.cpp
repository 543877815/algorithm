// 动态规划
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        int n = str1.size(), m = str2.size();
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int index = -1;
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (str1[i] == str2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    if (dp[i + 1][j + 1] > maxLength) {
                        maxLength = dp[i + 1][j + 1];
                        index = i - maxLength + 1;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
//         cout << index << " " << maxLength;
        if (maxLength == 0) return "-1";
        return str1.substr(index, maxLength);
    }
};