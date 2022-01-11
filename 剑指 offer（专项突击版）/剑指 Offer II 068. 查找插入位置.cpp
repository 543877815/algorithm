// 二分查找
// 时间复杂度：O(logn)
// 空间复杂度：O(logn)
class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};