// ��̬�滮
// ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * �����������ϸ����������еĳ��ȡ�
     * @param arr int����vector ����������
     * @return int����
     */
    int LIS(vector<int>& arr) {
        // write code here
        int n = arr.size();
        if (n == 0) return 0;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        int res = 1;
        for (int i = 0; i < n; i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};