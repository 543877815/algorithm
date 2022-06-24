// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    int jump(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if (j + i < n) {
                    dp[j + i] = min(dp[j + i], dp[i] + 1);
                } else {
                    break;
                }
            }
        }

        return dp[n - 1];
    }
};

// 贪心反向查找
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    int jump(vector<int> &nums) {
        int position = nums.size() - 1;
        int steps = 0;
        while (position > 0) {
            for (int i = 0; i < position; i++) {
                if (i + nums[i] >= position) {
                    position = i;
                    steps++;
                    break;
                }
            }
        }
        return steps;
    }
};

// 贪心正向查找
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; i++) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    step++;
                }
            }
        }
        return step;
    }
};