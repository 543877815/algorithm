// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        int res = 1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxVal) {
                count++;
            } else {
                count = 0;
            }
            res = max(res, count);
        }
        return res;
    }
};