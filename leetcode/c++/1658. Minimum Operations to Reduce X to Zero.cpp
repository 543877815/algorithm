// 滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int target = sum - x;
        int curr = 0;
        int right = 0, left = 0;
        int maxn = -1;
        while (right < n && left < n) {
            if (curr == target) {
                maxn = max(maxn, right - left);
                curr += nums[right++];
                curr -= nums[left++];
            } else if (curr < target) {
                curr += nums[right++];
            } else {
                curr -= nums[left++];
            }
        }
        while (left < n && curr > target) {
            curr -= nums[left++];
        }

        if (curr == target) {
            maxn = max(maxn, right - left);
        }
        return maxn == -1 ? maxn : n - maxn;
    }
};