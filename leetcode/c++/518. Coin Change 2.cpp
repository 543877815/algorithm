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


// 动态规划
// 时间复杂度：O(n*amount)
// 空间复杂度：O(n*amount)
class Solution {
public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        vector <vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i - 1] >= 0) dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][amount];
    }
};