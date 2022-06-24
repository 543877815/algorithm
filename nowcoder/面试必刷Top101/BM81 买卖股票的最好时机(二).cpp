// ̰���㷨
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * �����������
     * @param prices int����vector ��Ʊÿһ��ļ۸�
     * @return int����
     */
    int maxProfit(vector<int> &prices) {
        // write code here
        int n = prices.size();
        if (n == 0 || n == 1) return 0;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1])
                ans += prices[i] - prices[i - 1];
        }
        return ans;
    }
};

// ��̬�滮
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * �����������
     * @param prices int����vector ��Ʊÿһ��ļ۸�
     * @return int����
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[n-1][0];
    }
};