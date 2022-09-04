// 时间复杂度：O(k)
// 空间复杂度：O(n)
// 动态规划
class Solution {
public:
    int getIdx(int idx) {
        return idx + 1501;
    }

    int MOD = 1000000007;
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<long long>> dp = vector<vector<long long>>(k + 1, vector<long long>(3100, 0));
        dp[0][getIdx(startPos)]++;

        for (int i = 1; i <= k; i++) {
            for (int j = -1500; j <= 1501; j++) {
                dp[i][getIdx(j)] = (dp[i-1][getIdx(j+1)] % MOD + dp[i-1][getIdx(j-1)] % MOD) % MOD;
            }
        }

        return dp[k][getIdx(endPos)] % MOD;
    }
};