class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // 重构
        int n = startTime.size();
        vector<vector<int>> nums(n, vector<int>(3, 0));
        for (int i = 0; i < n; ++i) {
            nums[i][0] = startTime[i];
            nums[i][1] = endTime[i];
            nums[i][2] = profit[i];
        }
        // 按结束时间排序
        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        // 初始化dp, n + 1 利于数组越界处理
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            // 二分查找
            int l = 1, r = n;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[mid - 1][1] <= nums[i - 1][0]) l = mid + 1; // l 左侧均满足结束时间比 i 的开始时间早
                else r = mid - 1;
            }
            dp[i] = max(dp[i - 1], dp[l - 1] + nums[i - 1][2]);
        }
        return dp[n];
    }
};

