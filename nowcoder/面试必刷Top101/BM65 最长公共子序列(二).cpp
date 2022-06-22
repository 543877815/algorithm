// 时间复杂度：O(nm)
// 空间复杂度：O(nmK) K 为序列长度
// 内存超了
class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        // write code here
        int n = s1.size(), m = s2.size();
        if (n == 0 || m == 0) return "-1";
        // dp[i][j] 表示 s1 前 i 个字符和 s2 前 j 个字符的最长公共子序列
        vector<vector<string>> dp = vector<vector<string>>(n+1, vector<string>(m+1, ""));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                } else {
                    dp[i][j] = dp[i][j-1].size() > dp[i-1][j].size() ? dp[i][j-1] : dp[i-1][j];
                }
            }
        }
        return dp[n][m].size() == 0 ? "-1" : dp[n][m];
    }
};

// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
// 动态规划+栈优化
class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string text1, string text2) {
        // write code here
        int n = text1.size();
        int m = text2.size();
        if (n == 0 || m == 0) return "-1";
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        stack<char> sk;
        int i = n, j = m;
        while (dp[i][j]) {
            if (dp[i][j] == dp[i][j-1]) {
                j--;
            } else if (dp[i][j] == dp[i-1][j]) {
                i--;
            } else if (dp[i][j] == dp[i-1][j-1] + 1) {
                i--;
                j--;
                sk.push(text1[i]);
            }
        }

        string res = "";
        while (!sk.empty()) {
            res += sk.top();
            sk.pop();
        }
        return res != "" ? res : "-1";
    }
};
