// 空间复杂度：O(k)
// 时间复杂度：O(n)
class Solution {
private:
    int maxProfitINF(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int dp_i_0 = 0; // 第i天卖出收益
        int dp_i_1 = -prices[0]; // 第i天买入收益
        for (int i = 0; i < n; i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }

public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (n <= 1 || k == 0) return 0;
        if (k > n / 2) return maxProfitINF(prices);
        int dp_i_0[k];
        int dp_i_1[k];
        for (int j = 0; j < k; j++) {
            dp_i_0[j] = 0;           // 第i天第j次卖出
            dp_i_1[j] = -prices[0];  // 第i天第j次买入
        }
        for (int i = 0; i < n; i++) {
            for (int j = k - 1; j >= 0; j--) {
                if (j > 0) {
                    int temp = dp_i_0[j];
                    dp_i_0[j] = max(dp_i_0[j], dp_i_1[j] + prices[i]);
                    dp_i_1[j] = max(dp_i_1[j], dp_i_0[j - 1] - prices[i]);
                } else {
                    dp_i_0[j] = max(dp_i_0[j], dp_i_1[j] + prices[i]);
                    dp_i_1[j] = max(dp_i_1[j], -prices[i]);
                }
            }
        }
        return dp_i_0[k - 1];
    }
};

// 优化
class Solution {
private:
    int maxProfitINF(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int dp_i_0 = 0; // 第i天卖出收益
        int dp_i_1 = -prices[0]; // 第i天买入收益
        for (int i = 0; i < n; i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }

public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (n <= 1 || k == 0) return 0;
        if (k > n / 2) return maxProfitINF(prices);
        int dp_i_0[k + 1];
        int dp_i_1[k + 1];
        for (int j = 0; j < k + 1; j++) {
            dp_i_0[j] = 0;           // 第i天第j次卖出
            dp_i_1[j] = -prices[0];  // 第i天第j次买入
        }
        for (int i = 0; i < n; i++) {
            for (int j = k; j >= 1; j--) {
                int temp = dp_i_0[j];
                dp_i_0[j] = max(dp_i_0[j], dp_i_1[j] + prices[i]);
                dp_i_1[j] = max(dp_i_1[j], dp_i_0[j - 1] - prices[i]);
            }
        }
        return dp_i_0[k];
    }
};

// 动态规划
// 时间复杂度：O(nk)
// 空间复杂度：O(nk)
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        int res = 0;
        if (n == 0 || k == 0) return res;
        // dp[i][0]表示到第i天为止没有买过股票的最大收益
        // dp[i][2k-1]表示到第i天为止买过k次股票卖出k-1次股票最大收益
        // dp[i][2k]表示到第i天为止买过k次也卖出过k次股票的最大收益
        vector <vector<int>> dp(n, vector<int>(2 * k + 1, -1000 * k));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j <= k; j++) {
                dp[i][2 * j - 1] = max(dp[i - 1][2 * j - 1], dp[i - 1][2 * j - 1 - 1] - prices[i]);
                dp[i][2 * j] = max(dp[i - 1][2 * j], dp[i - 1][2 * j - 1] + prices[i]);
            }
        }
        for (int i = 1; i <= k; i++) {
            res = max(res, dp[n - 1][2 * i]);
        }

        return res;
    }
};