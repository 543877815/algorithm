// 单调栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> res = vector<int>(n, 0);
        stack <pair<int, int>> sk;
        for (int i = 0; i < n; i++) {
            while (!sk.empty() && sk.top().second < temperatures[i]) {
                res[sk.top().first] = i - sk.top().first;
                sk.pop();
            }
            sk.push(make_pair(i, temperatures[i]));
        }

        while (!sk.empty()) {
            res[sk.top().first] = 0;
            sk.pop();
        }
        return res;
    }
};