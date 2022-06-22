// ��̬�滮+���ֲ���
// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    vector<int> LIS(vector<int>& arr) {
        int n = arr.size();
        // dp[i]��ʾ����Ϊ i ������������е�ĩβԪ�ص���Сֵ.
        // p[i]��ʾ��ǰԪ�ض�Ӧ�ĳ���
        vector<int> dp(n + 1, -1), p(n);
        int len = 1;//��ʼ������Ϊ1��Ԫ��Ϊ���е�һ������
        dp[len] = arr[0];
        p[0] = 1;
        for(int i = 1; i < n; ++i) {
            if(arr[i] > dp[len]) {
                //��ʱ����������ӵ�ĩβ
                dp[++len] = arr[i];
                p[i] = len;
            } else {
                //���ֲ���ǡ�ú��ʵ�λ��
                int left = 1, right = len, pos = 0;
                while(left <= right) {
                    int mid = (left + right) / 2;
                    if(dp[mid] < arr[i]) {
                        pos = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                //�Ը�λ�����ֽ��и���
                dp[pos + 1] = arr[i];
                p[i] = pos + 1;
            }
        }
        vector<int> ans(len);
        //������Ҷ�Ӧ����ֵ
        for(int i = n - 1; i >= 0; --i) {
            if(p[i] == len) {
                ans[--len] = arr[i];
            }
        }
        return ans;
    }
};