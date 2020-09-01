// 递归
// 时间复杂度：O(2^n)
// 空间复杂度：O(n)
class Solution {
public:
    bool PredictTheWinner(vector<int> &nums) {
        return total(nums, 0, nums.size() - 1, 1) >= 0;
    }

    int total(vector<int> &nums, int start, int end, int turn) {
        if (start == end) {
            return nums[start] * turn;
        }
        int scoreStart = nums[start] * turn + total(nums, start + 1, end, -turn);
        int scoreEnd = nums[end] * turn + total(nums, start, end - 1, -turn);
        return max(scoreStart * turn, scoreEnd * turn) * turn;
    }
};

// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    bool PredictTheWinner(vector<int> &nums) {
        int n = nums.size();
        if ((n & 1) == 0) return true;
        // dp[i][j]表示第i元素到第j个元素中，当前玩家与另一个玩家的最大分数差
        vector <vector<int>> dp = vector < vector < int >> (n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (j - i == 1)
                    dp[i][j] = abs(nums[i] - nums[j]);
                else if (j - i > 1)
                    dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};