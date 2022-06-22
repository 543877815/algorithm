// 动态规划
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector <vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

// 记忆化搜索
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:

    vector <vector<int>> dp;

    int search(string &text1, string &text2, int i, int j) {
        if (dp[i][j]) return dp[i][j];
        if (i == 0 && j == 0) {
            if (text1[i] == text2[j]) dp[i][j] = 1;
            return dp[i][j];
        } else if (i == 0) {
            if (text1[i] == text2[j]) dp[i][j] = 1;
            else dp[i][j] = search(text1, text2, i, j - 1);
            return dp[i][j];
        } else if (j == 0) {
            if (text1[i] == text2[j]) dp[i][j] = 1;
            else dp[i][j] = search(text1, text2, i - 1, j);
            return dp[i][j];
        }

        int a = 0, b = 0, c = 0;
        a = search(text1, text2, i - 1, j);
        b = search(text1, text2, i, j - 1);

        if (text1[i] == text2[j]) {
            c = search(text1, text2, i - 1, j - 1) + 1;
        }

        dp[i][j] = max(max(a, b), max(c, dp[i][j]));

        return dp[i][j];

    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        if (n == 0 || m == 0) return 0;
        dp = vector < vector < int >> (n + 1, vector<int>(m + 1, 0));
        return search(text1, text2, n - 1, m - 1);
    }
};