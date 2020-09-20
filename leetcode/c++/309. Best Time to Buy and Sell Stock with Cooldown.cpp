
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        // 记录第i天卖出的最大收益
        vector<int> sell(n, 0);
        // 记录到第i天最后一个操作是买进的最大收益
        vector<int> buy(n, 0);
        // 记录到第i天是冻结状态的最大收益
        vector<int> cool(n, 0);
        buy[0] = -prices[0];
        for (int i = 1; i n; i++) {
            sell[i] = buy[i - 1] + prices[i];
            buy[i] = max(buy[i - 1], cool[i - 1] - prices[i]);
            cool[i] = max(sell[i - 1], cool[i - 1]);
        }

        return max(sell[n - 1], cool[n - 1]);
    }
}

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        // 表示不持股
        vector<int> unhold(n, 0);
        // 表示持股
        vector<int> hold(n, 0);
        // 表示处在冷冻期
        vector<int> cool(n, 0);
        hold[0] = -prices[0];
        for (int i = 1; i < n; i++) {
            // 不持股：1.昨天不持股，今天依旧不持股；2.昨天持股，今天卖股票
            unhold[i] = max(unhold[i - 1], hold[i - 1] + prices[i]);
            // 持股：1.昨天持股，今天持股；2.昨天冷冻期，今天买了股
            hold[i] = max(hold[i - 1], cool[i - 1] - prices[i]);
            // 冷冻期只可以由不持股转换而来
            cool[i] = unhold[i - 1];
        }
        return max(cool[n - 1], unhold[n - 1]);
    }
}

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int sell = 0, hold = -prices[0], cool = 0;    // sell为卖出股票的行为，hold为购买股票的行为，cool为冷冻期
        for (int i = 1; i < n; i++) {
            hold = max(hold, cool - prices[i]);       // 今天购买股票的最大收益=max(昨天购买，昨天冷冻期但今天购买股票)
            cool = max(sell, cool);                   // 今天为冷冻期的最大收益=max(昨天卖出，昨天冷冻期)
            sell = hold + prices[i];                  // 今天卖出股票的最大收益=昨天购买股票的最大收益+今天得到的钱
        }
        return max(cool, sell);
    }
};

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int dp_i_0 = 0; // 第i天卖出获得的收益
        int dp_i_1 = -prices[0]; // 第i天买入获得的收益
        int dp_i_2 = 0; // 第i天冷冻期的收益
        for (int i = 0; i < n; i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]); // max(昨天卖了，今天卖了)
            dp_i_1 = max(dp_i_1, dp_i_2 - prices[i]); // max(昨天买了，昨天冷冻今天买)
            dp_i_2 = temp; // 昨天卖
        }
        return dp_i_0;
    }
};