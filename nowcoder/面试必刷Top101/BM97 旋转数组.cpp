// ���η�ת
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    /**
     * ��ת����
     * @param n int���� ���鳤��
     * @param m int���� ���ƾ���
     * @param a int����vector ��������
     * @return int����vector
     */
    vector<int> solve(int n, int m, vector<int>& a) {
        // write code here
        m = m % n;

        reverse(a.begin(), a.end());
        reverse(a.begin(), a.begin() + m);
        reverse(a.begin() + m, a.end());

        return a;
    }
};