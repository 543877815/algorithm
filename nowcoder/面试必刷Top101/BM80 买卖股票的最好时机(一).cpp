// ��̬�滮
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    /**
     *
     * @param prices int����vector
     * @return int����
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

// ̰���㷨
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    /**
     *
     * @param prices int����vector
     * @return int����
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

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    /**
     *
     * @param prices int����vector
     * @return int����
     */


    int maxProfit(vector<int> &prices) {
        // write code here
        int n = prices.size();
        int res = 0;
        if (n == 0) return res;
        /*
         * dp[i][j]���±�Ϊ i ��һ�������ʱ�����ϳֹ�״̬Ϊ j ʱ�����ǳ��е��ֽ�����
         * j = 0����ʾ��ǰ���ֹɣ�
         * j = 1����ʾ��ǰ�ֹɡ�
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