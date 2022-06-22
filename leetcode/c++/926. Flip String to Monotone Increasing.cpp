// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    // 用 dp[i][0] 和 dp[i][1] 分别表示下标 i 处的字符为 0 和 1 的情况下使得 s[0..i] 单调递增的最小翻转次数。
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> dp1(n + 1, 0);
        vector<int> dp0(n + 1, 0);
        dp1[0] = s[0] == '0';
        dp0[0] = s[0] == '1';
        for (int i = 1; i < n; i++) {
            dp0[i] = dp0[i - 1] + (s[i] == '1');
            dp1[i] = min(dp1[i - 1], dp0[i - 1]) + (s[i] == '0');
        }
        return min(dp1[n - 1], dp0[n - 1]);
    }
};