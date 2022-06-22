// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        for (int i = 1; i <= num; i++) {
            if (num - i * k < 0) break;
            if ((num - i * k) % 10 == 0) return i;
        }

        return -1;
    }
};