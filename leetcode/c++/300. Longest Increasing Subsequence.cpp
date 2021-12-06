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

// 贪心+二分搜索
// 空间复杂度：O(n)
// 时间复杂度：O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int len = 1, n = (int) nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } else {
                int pos = 0;
                auto it = lower_bound(d.begin() + 1, d.begin() + len + 1, nums[i]);
                if (it != d.end()) {
                    pos = (it - d.begin());
                }
                d[pos] = nums[i];
            }
        }
        return len;
    }
};