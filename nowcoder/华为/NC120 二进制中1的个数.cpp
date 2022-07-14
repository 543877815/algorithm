// n&n-1�������λ���0
// ʱ�临�Ӷȣ�O(1)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    int NumberOf1(int n) {
        int ans = 0;
        while (n != 0) {
            ++ans;
            n = n & (n - 1);
        }
        return ans;
    }
};

// ��λ�Ƚ�
// ʱ�临�Ӷȣ�O(1)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    int NumberOf1(int n) {
        int res = 0;
        //����32λ
        for (int i = 0; i < 32; i++) {
            //��λ�Ƚ�
            if ((n & (1 << i)) != 0)
                res++;
        }
        return res;
    }
};