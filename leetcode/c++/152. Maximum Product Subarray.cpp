// 超时
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, 0));
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
            res = max(res, nums[i]);
        }
        for (int r = 1; r < n; r++) {
            for (int i = 0; i < n - r; i++) {
                int j = i + r;
                dp[i][j] = dp[i+1][j] * nums[i];
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};