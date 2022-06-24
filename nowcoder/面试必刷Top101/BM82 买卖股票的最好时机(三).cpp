// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 两次交易所能获得的最大收益
     * @param prices int整型vector 股票每一天的价格
     * @return int整型
     */
    int maxProfit(vector<int> &prices) {
        // write code here
        // dp[i][0]表示到第i天为止没有买过股票的最大收益
        // dp[i][1]表示到第i天为止买过一次股票还没有卖出的最大收益
        // dp[i][2]表示到第i天为止买过一次也卖出过一次股票的最大收益
        // dp[i][3]表示到第i天为止买过两次只卖出过一次股票的最大收益
        // dp[i][4]表示到第i天为止买过两次同时也买出过两次股票的最大收益

        int n = prices.size();
        if (n == 0) return 0;
        vector <vector<int>> dp(n, vector<int>(5, -10000));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }

        return max(0, max(dp[n - 1][4], dp[n - 1][2]));
    }
};