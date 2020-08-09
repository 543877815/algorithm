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