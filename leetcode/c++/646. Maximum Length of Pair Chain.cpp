// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
// 动态规划
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int> dp(n, 1);
        sort(pairs.begin(), pairs.end());
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        return dp[n-1];
    }
};