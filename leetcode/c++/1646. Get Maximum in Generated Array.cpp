// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        int index = 2;
        int res = 0;
        while (index < n + 1) {
            dp[index] = index % 2 == 0 ? dp[index / 2] : dp[index / 2] + dp[index / 2 + 1];
            res = max(res, dp[index]);
            index++;
        }
        return res;
    }
};
