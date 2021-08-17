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

// 通过减法和二分搜索思想降低复杂度
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool positive = (long)dividend * divisor > 0;
        long dividend_L = abs(dividend);
        long divisor_L = abs(divisor);
        long res = 0;
        while (dividend_L >= divisor_L) {
            int index = 1;
            while (dividend_L > (divisor_L << index)) {
                index = index << 1;
            }
            dividend_L -= (divisor_L << (index >> 1 ));
            res += 1 << (index >> 1);
        }
        res = positive ? res : -res;
        return res > INT_MAX ? INT_MAX : (int) res;
    }
};