// ����ջ
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
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