// 单调栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        int n = T.size();
        stack<int> sk;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            while (!sk.empty() && T[sk.top()] < T[i]) {
                res[sk.top()] = i - sk.top();
                sk.pop();
            }
            sk.push(i);
        }

        return res;
    }
};