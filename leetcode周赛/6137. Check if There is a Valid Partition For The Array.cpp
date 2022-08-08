// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool isSame(vector<int> &nums, int left, int right) {
        for (int i = left+1; i <= right; i++) {
            if (nums[left] != nums[i]) return false;
        }
        return true;
    }

    bool isIncreasing(vector<int>& nums, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] - nums[i-1] != 1) return false;
        }

        return true;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, false);
        dp[0] = true;
        for (int i = 2; i <= n; i++) {
            if (i == 2) dp[i] |= dp[i-2] && isSame(nums, i-2, i-1);
            else {
                dp[i] |= dp[i-2] && isSame(nums, i-2, i-1);
                dp[i] |= dp[i-3] && (isSame(nums, i-3, i-1) || isIncreasing(nums, i-3, i-1));
            }
        }
        return dp[n];
    }
};