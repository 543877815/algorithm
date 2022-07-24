class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1) return true;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % k != 0) return false;
        int target = sum / k;
        if (nums.back() > target) return false;

        int size = 1 << n;
        vector<bool> dp(size, false);
        dp[0] = true;

        vector<int> currentSum = vector<int>(size);
        for (int i = 0; i < size; i++) {
            // 总是基于 dp[i] = true 的前提下进行状态转移
            if (!dp[i]) continue;

            // 基于当前状态，添加一个数以后
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) continue;
                int next = i | (1 << j);
                if (dp[next]) continue;
                if ((currentSum[i] % target) + nums[j] <= target) {
                    currentSum[next] = currentSum[i] + nums[j];
                    dp[next] = true;
                } else {
                    // 由于数组已经排好序，如果 (currentSum[i] % target) + nums[j] > target，剩下的数就没有必要枚举
                    break;
                }
            }
        }
        return dp[size - 1];
    }
};