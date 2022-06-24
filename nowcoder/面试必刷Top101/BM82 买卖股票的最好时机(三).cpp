// ��̬�滮
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * ���ν������ܻ�õ��������
     * @param prices int����vector ��Ʊÿһ��ļ۸�
     * @return int����
     */
    int maxProfit(vector<int> &prices) {
        // write code here
        // dp[i][0]��ʾ����i��Ϊֹû�������Ʊ���������
        // dp[i][1]��ʾ����i��Ϊֹ���һ�ι�Ʊ��û���������������
        // dp[i][2]��ʾ����i��Ϊֹ���һ��Ҳ������һ�ι�Ʊ���������
        // dp[i][3]��ʾ����i��Ϊֹ�������ֻ������һ�ι�Ʊ���������
        // dp[i][4]��ʾ����i��Ϊֹ�������ͬʱҲ��������ι�Ʊ���������

        int n = prices.size();
        if (n == 0) return 0;
        vector <vector<int>> dp(n, vector<int>(5, -10000));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }

        return max(0, max(dp[n - 1][4], dp[n - 1][2]));
    }
};