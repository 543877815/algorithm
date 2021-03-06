// 单调栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> mostCompetitive(vector<int> &nums, int k) {
        int n = nums.size();
        stack<int> sk;
        for (int i = 0; i < n; i++) {
            while (!sk.empty() && sk.top() > nums[i] && n - i + sk.size() > k) {
                sk.pop();
            }
            sk.push(nums[i]);
        }

        vector<int> res(k);
        int index = k - 1;
        while (!sk.empty()) {
            while (sk.size() > k) sk.pop();
            res[index--] = sk.top();
            sk.pop();
        }
        return res;
    }
};