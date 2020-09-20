// 时间复杂度：O(n*target)
// 空阿复杂度：O(target)
class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        int n = nums.size();
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++) {
                if (i - nums[j] >= 0 && nums[j] <= target) {
                    dp[i] += dp[i - nums[j]];
                }

            }
        }
        return dp[target];
    }
};

