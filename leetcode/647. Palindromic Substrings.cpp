// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        // dp[i][j] 表示从字符串i到j是否为回文串
        vector <vector<bool>> dp(n, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == j) {
                    dp[i][j] = true;
                    res++;
                } else if (i - j == 1 && s[i] == s[j]) {
                    dp[i][j] = true;
                    res++;
                } else if (i - j > 1 && s[i] == s[j] && dp[i - 1][j + 1]) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};


// 优化
// 空间复杂度：O(n^2)
// 时间复杂度：O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
        return ans;
    }
};
