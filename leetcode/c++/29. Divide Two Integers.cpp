// 瞎搞
// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
        double res = (double) dividend / divisor;
        return res >= 2147483648 ? 2147483647 : (int) res;
    }
};