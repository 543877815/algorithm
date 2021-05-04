// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
public:
    bool canCross(vector<int> &stones) {
        int n = stones.size();
        vector <vector<int>> dp(n, vector<int>(n));
        dp[0][0] = true;
        for (int i = 1; i < n; i++) {
            if (stones[i] - stones[i - 1] > i) {
                return false;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int k = stones[i] - stones[j];
                if (k > j + 1) break;
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if (i == n - 1 && dp[i][k]) {
                    return true;
                }
            }
        }
        return false;
    }
};