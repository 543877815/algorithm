// 排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(lgn)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0) return 0;
        int res = 1;
        int curr = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1] + 1) curr++;
            else if (nums[i] - nums[i-1] > 1) curr = 1;
            res = max(res, curr);
        }

        return res;
    }
};