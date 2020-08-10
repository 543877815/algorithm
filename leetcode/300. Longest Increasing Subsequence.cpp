// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int max_num = 1;

        // dp[i] 表示以第i个数字为结尾的最长上升子序列的长度
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    max_num = max(max_num, dp[i]);
                }
            }
    }
        return max_num;
    }
};