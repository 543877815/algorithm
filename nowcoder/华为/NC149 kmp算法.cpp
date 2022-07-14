// ʱ�临�Ӷȣ�O(n+m)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ����ģ�崮S���ı���T�г����˶��ٴ�
     * @param S string�ַ��� ģ�崮
     * @param T string�ַ��� �ı���
     * @return int����
     */
    int kmp(string S, string T) {
        // write code here
        int n = S.size(), m = T.size();
        vector<int> next(n, 0);  // next ��ʾ��ǰ׺�����ͬ�Ӵ�����
        int len = 0;
        int i = 1;
        while (i < n) {
            if (S[len] == S[i]) {
                len++;
                next[i] = len;
                i++;
            } else {
                if (len == 0) {
                    i++;
                } else {
                    len = next[len - 1];  // �˴������̵�ǰ��׺
                }
            }
        }

        int res = 0;
        i = 0; // ����
        int j = 0;  // �Ӵ�
        while (i < m) {
            if (S[j] == T[i]) {
                i++;
                j++;
            } else if (j > 0) {
                j = next[j - 1];
            } else {
                i++;
            }

            if (j == n) {
                res++;
            }
        }

        return res;
    }
};