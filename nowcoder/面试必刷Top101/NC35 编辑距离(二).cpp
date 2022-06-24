// ��̬�滮
// ʱ�临�Ӷȣ�O(nm)
// �ռ临�Ӷȣ�O(nm)
/*
 * �滻/����  ɾ��
 *   ����    ��  ��
 *
 */
class Solution {
public:
    /**
     * min edit cost
     * @param str1 string�ַ��� the string
     * @param str2 string�ַ��� the string
     * @param ic int���� insert cost
     * @param dc int���� delete cost
     * @param rc int���� replace cost
     * @return int����
     */
    int minEditCost(string str1, string str2, int ic, int dc, int rc) {
        // write code here
        int n = str1.size(), m = str2.size();
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = i * dc;
        }

        for (int j = 1; j <= m; j++) {
            dp[0][j] = j * ic;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + dc, min(dp[i][j - 1] + ic, dp[i - 1][j - 1] + rc));
                }
            }
        }

        return dp[n][m];
    }
};