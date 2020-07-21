// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                break;
            }
            if (abs(nums[left + 1] + nums[right] - target) < abs(nums[left] + nums[right - 1] - target)) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};