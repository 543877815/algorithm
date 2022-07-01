// 超时
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        vector <vector<int>> dp = vector < vector < int >> (n, vector<int>(n, 0));
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
            res = max(res, nums[i]);
        }
        for (int r = 1; r < n; r++) {
            for (int i = 0; i < n - r; i++) {
                int j = i + r;
                dp[i][j] = dp[i + 1][j] * nums[i];
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(1)
/*
 * 遍历数组时计算当前最大值，不断更新
 * 令imax为当前最大值，则当前最大值为 imax = max(imax * nums[i], nums[i])
 * 由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值imin，imin = min(imin * nums[i], nums[i])
 */
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        int res = INT_MIN, imax = 1, imin = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) swap(imax, imin);
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            res = max(res, imax);
        }

        return res;
    }
};