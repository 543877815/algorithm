// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int dp_i_0 = 0; // 第i天第一次卖出
        int dp_i_1 = -prices[0]; // 第i天第一次买入
        int dp_i_2 = 0; // 第i天第二次卖出
        int dp_i_3 = -prices[0]; // 第i天第二次买入
        for (int i = 0; i < n; i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]); // max(之前卖出，之前买入现在卖出)
            dp_i_1 = max(dp_i_1, -prices[i]);         // max(之前买入，现在卖出)
            dp_i_2 = max(dp_i_2, dp_i_3 + prices[i]); // max(之前卖出，第一次买入后卖出)
            dp_i_3 = max(dp_i_3, temp - prices[i]); // max(之前买入，第一次卖出之后再买入)
        }
        return dp_i_2;
    }
};


// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int dp[2][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = 0;
        dp[1][1] = -prices[0];
        for (int i = 0; i < n; i++) {
            int temp = dp[0][0];
            dp[0][0] = max(dp[0][0], dp[0][1] + prices[i]); // max(之前卖出，之前买入现在卖出)
            dp[0][1] = max(dp[0][1], -prices[i]);           // max(之前买入，现在卖出)
            dp[1][0] = max(dp[1][0], dp[1][1] + prices[i]); // max(之前卖出，第一次买入后卖出)
            dp[1][1] = max(dp[1][1], temp - prices[i]);     // max(之前买入，第一次卖出之后再买入)
        }
        return dp[1][0];
    }
};

