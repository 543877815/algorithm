// 动态规划，超时
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int  n = nums.size();
        int res = 0;
        vector<vector<long>> dp(n+1, vector<long>(n+1, 0));
        for (int i = 1; i < n+1; i++) dp[i][i] = nums[i-1];
        for (int i = 1; i < n+1; i++) {
            for (int j = i+1; j < n+1; j++) {
                dp[i][j] = dp[i][j - 1] + nums[j - 1];
            }
        }
        for (int i = 1; i < n+1; i++) {
            for (int j = i; j < n+1; j++) {
                if (dp[i][j] <= upper && dp[i][j] >= lower) res++;
            }
        }
        return res;
    }
};