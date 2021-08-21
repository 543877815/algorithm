// 双指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if (k <= 1) return 0;
        int total = 1;
        int res = 0;
        int left = 0, right = 0;
        while (left <= right && right < n) {
            total *= nums[right];
            while (total >= k) {
                total /= nums[left++];
            }
            res += right - left + 1;
            right ++;
        }
        return res;
    }
};