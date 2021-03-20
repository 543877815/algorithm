// 时间复杂度：O(32)
// 空间复杂度：O(1)
class Solution {
public:
    int add(int a, int b) {
        int sum, carry;
        while (b != 0) {
            // 异或操作得无进位和
            sum = a ^ b;
            // 与操作后移位得进位值
            carry = ((unsigned int) (a & b) << 1);
            // 循环，直到进位为0
            a = sum;
            b = carry;
        }
        return a;
    }
};