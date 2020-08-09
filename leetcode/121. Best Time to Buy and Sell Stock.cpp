#define INF 0x7fffffff

int max(int a, int b) {
    return a > b ? a : b;
}

int maxProfit(int *prices, int pricesSize) {
    if (pricesSize == 0 || pricesSize == 1) return 0;
    int ans = prices[1] - prices[0];
    int minPrice = INF;
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
        ans = max(ans, prices[i] - minPrice);
    }
    return ans > 0 ? ans : 0;
}


// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0 || n == 1) return 0;
        int ans = prices[1] - prices[0];
        int minPrice = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (prices[i] < minPrice)
                minPrice = prices[i];
            ans = max(ans, prices[i] - minPrice);
        }

        return ans;
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
        int dp_i_0 = 0; // 第i天卖出
        int dp_i_1 = -prices[0]; // 第i天买入
        for (int i = 0; i < n; i++) {
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);  // max(昨天卖出，今天卖出)
            dp_i_1 = max(dp_i_1, -prices[i]);          // max(昨天买入，今天买入)
        }
        return dp_i_0;
    }
};