// ��̬�滮
// ʱ�临�Ӷȣ�O(nm)
// �ռ临�Ӷȣ�O(nm)
class Solution {
public:
    /**
     *
     * @param m int����
     * @param n int����
     * @return int����
     */
    int uniquePaths(int m, int n) {
        // write code here
        vector <vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};