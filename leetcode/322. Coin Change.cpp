// 动态规划，容易超时，S是金额，n是面额数
// 时间复杂度：O(Sn)
// 空间复杂度：O(S)
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        if (n == 0) return -1;
        if (amount == 0) return 0;
        int MAX = amount + 1;
        vector<int> res(amount + 1, MAX);
        sort(coins.begin(), coins.end());
        int max_iter = amount / coins[0];
        for (int i = 0; i < n && coins[i] <= amount; i++) {
            res[coins[i]] = 1;
        }
        for (int i = 0; i < max_iter; i++) {
            if (res[amount] != MAX) return res[amount];
            for (int j = amount; j >= 0; j--) {
                for (int k = 0; k < n && j - coins[k] > 0; k++) {
                    res[j] = min(res[j], res[j - coins[k]] + 1);
                }
            }
        }
        return res[amount] == MAX ? -1 : res[amount];
    }
};

// 优化
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        if (n == 0) return -1;
        if (amount == 0) return 0;
        int MAX = amount + 1;
        vector<int> dp(amount + 1, MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == MAX ? -1 : dp[amount];
    }
};