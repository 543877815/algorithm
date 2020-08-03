// 时间复杂度：O(1)
// 空间复杂度：O(1)
/*
 * 数字   a  20 = 0 0 0 1 0 1 0 0
 *        +
 * 数字   b  17 = 0 0 0 1 0 0 0 1
 *        ||
 * 进位和 n       0 0 0 0 0 1 0 1     n = a ^ b
 *        +
 * 进位   c       0 0 1 0 0 0 0 0     c = a & b << 1
 *        ||
 * 和     s  37 = 0 0 1 0 0 1 0 1
 */
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