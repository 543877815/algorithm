// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        int n = nums.size();
        vector<int> min_prefix(n);
        stack<int> stk;
        min_prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            min_prefix[i] = min(min_prefix[i - 1], nums[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > min_prefix[i]) {
                while (!stk.empty() && stk.top() <= min_prefix[i])
                    stk.pop();
                if (!stk.empty() && min_prefix[i] < nums[i] && nums[i] > stk.top())
                    return true;
                stk.push(nums[i]);
            }
        }
        return false;
    }
};