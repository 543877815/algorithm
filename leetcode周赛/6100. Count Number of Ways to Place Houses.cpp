// ��̬�滮
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    long long MOD = 1000000007;

    int countHousePlacements(int n) {
        vector <vector<long long>> dp(n, vector<long long>(2, 0));
        dp[0][1] = 1;    // 1��ʾ�ŷ��ӣ�0��ʾ���ŷ���
        dp[0][0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][1] = dp[i - 1][0] % MOD;
        }

        return (((dp[n - 1][0] + dp[n - 1][1]) % MOD) * ((dp[n - 1][0] + dp[n - 1][1]) % MOD)) % MOD;
    }
};