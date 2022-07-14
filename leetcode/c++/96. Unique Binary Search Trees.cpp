// ��������
// ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i + 1; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }

        return dp[n];
    }
};