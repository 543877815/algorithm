// 单调栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> finalPrices(vector<int> &prices) {
        vector<int> res;
        int n = prices.size();
        if (n == 0) return res;
        stack<int> sk;
        for (int i = n - 1; i >= 0; i--) {
            while (!sk.empty() && sk.top() > prices[i]) {
                sk.pop();
            }
            int tmp = prices[i];
            if (!sk.empty()) prices[i] = prices[i] - sk.top();
            sk.push(tmp);
        }

        return prices;
    }
};