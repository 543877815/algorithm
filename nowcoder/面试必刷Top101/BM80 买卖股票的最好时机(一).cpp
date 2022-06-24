// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(vector<int> &prices) {
        // write code here
        int n = prices.size();
        vector<int> max_prices(n, 0);
        int max_price = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            max_price = max(max_price, prices[i]);
            max_prices[i] = max_price;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, max_prices[i] - prices[i]);
        }

        return res;
    }
};

// 贪心算法
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(vector<int> &prices) {
        // write code here
        int n = prices.size();
        int min_price = 10000;

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return res;
    }
};

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     *
     * @param prices int整型vector
     * @return int整型
     */


    int maxProfit(vector<int> &prices) {
        // write code here
        int n = prices.size();
        int res = 0;
        if (n == 0) return res;
        /*
         * dp[i][j]：下标为 i 这一天结束的时候，手上持股状态为 j 时，我们持有的现金数。
         * j = 0，表示当前不持股；
         * j = 1，表示当前持股。
        */
        vector <vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }

        return dp[n - 1][0];
    }
};