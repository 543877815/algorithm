// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int change(int amount, vector<int> &coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int j = 0; j < coins.size(); j++) {
            int coin = coins[j];
            for (int i = 1; i <= amount; i++) {
                if (i - coin >= 0) {
                    dp[i] = dp[i] + dp[i - coin];
                }
            }
        }
        return dp[amount];
    }
};