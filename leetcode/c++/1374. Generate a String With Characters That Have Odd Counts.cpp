// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    string generateTheString(int n) {
        string res = "";
        if (n == 0) return res;

        for (int i = 0; i < n; i++) {
            res += "a";
        }
        if (n % 2 == 0) {
            res[n - 1] = 'b';
        }
        return res;
    }
};