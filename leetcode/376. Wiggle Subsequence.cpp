// 动态规划，沿用300的思路
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return n;
        for (int i = 0; i < n - 1; i++) {
            nums[i] = nums[i + 1] - nums[i];
        }
        int max_num = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1])
                max_num = 1;
        }

        // dp[i] 表示以第i个数字为结尾的摆动序列的长度
        vector<int> dp(n, 1);
        for (int i = 1; i < n - 1; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] * nums[j] < 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    max_num = max(max_num, dp[i]);
                }
            }
        }
        return max_num + 1;
    }
};

// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return n;
        int up = 1, down = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                up = down + 1;
            }
            if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};