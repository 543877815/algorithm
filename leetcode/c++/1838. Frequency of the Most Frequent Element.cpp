// 排序+栈
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    int maxFrequency(vector<int> &nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = 1;
        long long count = 0;
        int res = 1;
        while (right < n) {
            count += (long long) (nums[right] - nums[right - 1]) * (right - left);
            while (count > k) {
                count -= nums[right] - nums[left];
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }
};
