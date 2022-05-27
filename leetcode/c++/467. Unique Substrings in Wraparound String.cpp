// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    // dp[i]表示以字母i结尾的最大子字符串数量
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        vector<int> dp(26, 0);
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (i && (p[i] - p[i-1] + 26) % 26 == 1) k++;
            else k = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }

        return accumulate(dp.begin(), dp.end(), 0);
    }
};