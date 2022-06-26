// ��̬�滮
// ʱ�临�Ӷȣ�O(Vn)
// �ռ临�Ӷȣ�O(Vn)
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * ����01��������Ľ��
     * @param V int���� ���������
     * @param n int���� ��Ʒ�ĸ���
     * @param vw int����vector<vector<>> ��һά��Ϊn,�ڶ�ά��Ϊ2�Ķ�ά����,vw[i][0],vw[i][1]�ֱ�����i+1����Ʒ��vi,wi
     * @return int����
     */
    int knapsack(int V, int n, vector <vector<int>> &vw) {
        // write code here
        // dp[i][j] ��ʾǰi�����壬��ǰ���������Ϊj������װ�µ�����ֵ��dp[i][j]
        vector <vector<int>> dp(n + 1, vector<int>(V + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= V; j++) {
                if (j - vw[i - 1][0] < 0) { // ���̫С
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vw[i - 1][0]] + vw[i - 1][1]);        // ��iװ���������߲���iװ������
                }
            }
        }

        return dp[n][V];
    }
};