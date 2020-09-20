// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int tribonacci(int n) {
        vector<int> nums = {0, 1, 1};
        for (int i = 3; i <= n; i++) {
            nums.push_back(nums[i - 1] + nums[i - 2] + nums[i - 3]);
        }
        return nums[n];
    }
};