// 递归
// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
bool isMatch(char *s, char *p) {
    if (*p == '\0') return *s == '\0';//查看是否二者都进行到末尾

    //think,p+1 or p+2 will not exceed the limit of array
    if (*(p + 1) != '*') {
        if (*p == *s || *p == '.' && *s != '\0')
            return isMatch(s + 1, p + 1);
        return false;
    } else {
        while (*p == *s || *p == '.' && *s != '\0') {
            if (isMatch(s, p + 2))
                return true;
            s++;
        }
        return isMatch(s, p + 2);
    }
}


// 动态规划
// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    bool isMatch(string s, string p) {
        s = " " + s;
        p = " " + p;
        int m = s.size();
        int n = p.size();
        // dp[i][j] 表示 s前i个字符和p前j个字符的匹配情况
        vector <vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] != '*') {
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else {
                    if (s[i - 1] != p[j - 2] && p[j - 2] != '.') {
                        dp[i][j] = dp[i][j - 2];
                    } else {
                        dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};