// ��̬�滮+���ֲ���
// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ��������ϸ����������еĳ���
     * @param a int����vector ����������
     * @return int����
     */
    int LIS(vector<int> &a) {
        // write code here
        int n = a.size();
        if (n == 0) return 0;
        // dp[i]��ʾ����Ϊ i ������������е�ĩβԪ�ص���Сֵ
        vector<int> dp(n + 1, 0);
        int len = 1;
        dp[len] = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > dp[len]) {
                dp[++len] = a[i];
            } else {
                int l = 1, r = len, pos = 0; // ����Ҳ���˵�����е������� nums[i] �󣬴�ʱҪ���� d[1]���������ｫ pos ��Ϊ 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (dp[mid] < a[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                dp[pos + 1] = a[i];
            }
        }
        return len;
    }
};

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ��������ϸ����������еĳ���
     * @param a int����vector ����������
     * @return int����
     */
    int LIS(vector<int>& a) {
        // write code here
        int n = a.size();
        if (n == 0) return 0;
        // dp[i]��ʾ����Ϊ i ������������е�ĩβԪ�ص���Сֵ
        vector<int>dp(n+1, 0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int left = 0, right = res;
            while (left < right) {
                int mid = (left + right) / 2;
                if (dp[mid] < a[i]) left = mid + 1;
                else right = mid;
            }
            dp[left] = a[i];
            if (res == right) res++;
        }
        return res;
    }
};