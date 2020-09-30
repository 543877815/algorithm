// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n > 0) {
            n /= 5;
            res += n;
        }
        return res;
    }
};