// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int maxSize = 1;
        int maxVal = nums[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxVal = nums[i];
            }
        }

        vector<int> res;
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] == maxSize) {
                if (maxVal % nums[i] == 0) {
                    maxSize--;
                    maxVal = nums[i];
                    res.push_back(maxVal);
                }
            }
        }
        return res;
    }
};