// 前缀和原地修改
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            nums[i] = nums[i - 1] + nums[i];
        }

        return nums;
    }
};