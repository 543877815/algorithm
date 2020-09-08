// 时间复杂度：O(i-j)
// 空间复杂度：O(1)
// 思路：
// 1. 把 N 中 i - j 的位置置零先
// 2. 把 M 左移 i 位后和 N 相加
class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        for (int k = i; k <= j; k++) {
            if (N & (1 << k)) {
                N -= (1 << k);
            }
        }
        M = M << i;
        return N + M;
    }
};