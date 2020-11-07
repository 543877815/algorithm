// 动态规划，dp[i][j]表示的是word1中前i个字符与word2中前j个字符的编辑距离
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector <vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m + 1; i++) dp[i][0] = i;
        for (int j = 0; j < n + 1; j++) dp[0][j] = j;
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                int a = dp[i][j - 1] + 1;
                int b = dp[i - 1][j] + 1;
                int c = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) c += 1;
                dp[i][j] = min(a, min(b, c));
            }
        }
        return dp[m][n];
    }
};