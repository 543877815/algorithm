// 时间复杂度：O(n）
// 空间复杂度：O(1)
class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        int dp_i_0 = 0;  // 第i天卖出股票收益
        int dp_i_1 = -prices[0]; // 第i天购买股票收益
        for (int i = 0; i < n; i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i] - fee); // max(昨天卖出，今天卖出)
            dp_i_1 = max(dp_i_1, dp_i_0 - prices[i]); // max(昨天买入，昨天卖了今天买)
        }
        return dp_i_0;
    }
};