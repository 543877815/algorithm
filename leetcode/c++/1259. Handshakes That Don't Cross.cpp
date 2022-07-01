// 卡特兰数
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    const int MOD = 1000000007;

    int numberOfWays(int numPeople) {
        vector<long long> dp(numPeople / 2 + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= numPeople / 2; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += (dp[j - 1] * dp[i - j]) % MOD;
            }
            dp[i] = dp[i] % MOD;
        }

        return dp[numPeople / 2];
    }
};