// ģ��
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
#include<iostream>

using namespace std;

int main() {
    int n; // ��ƿ������
    while (cin >> n) {
        if (n == 0) return 0;
        int res = 0;
        int curr = n / 3; // ���Ի��Ŀ���
        n = n % 3; // ʣ�µ�ƿ������
        res += curr;
        while (curr > 0) {
            n += curr;
            curr = n / 3;
            n = n % 3;
            res += curr;
        }

        if (n == 2) res++;
        cout << res << endl;
    }
    return 0;
}