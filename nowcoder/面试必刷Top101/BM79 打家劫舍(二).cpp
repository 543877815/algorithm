// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int rob(vector<int> &nums) {
        // write code here
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        if (n == 3) return max(nums[0], max(nums[1], nums[2]));
        vector<int> dp(n + 1, 0);
        // 从 i = 1 开始找到 i = n - 1;
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for (int i = 3; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        int res = max(dp[n - 1], dp[n - 2]);

        // 从 i = n - 2 开始找到 i = 0;
        dp[n - 2] = nums[n - 2];
        dp[n - 3] = max(nums[n - 2], nums[n - 3]);
        for (int i = n - 4; i >= 0; i--) {
            dp[i] = max(dp[i + 2] + nums[i], dp[i + 1]);
        }

        res = max(res, max(dp[0], dp[1]));

        return res;
    }
};