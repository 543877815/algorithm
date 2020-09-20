// 快速幂解析
// 时间复杂度：O(log_2n)
// 空间复杂度：O(1)
class Solution {
public:
    double myPow(double x, int n) {
        bool x_pos = x >= 0;
        bool n_pos = n >= 0;

        double res = powerWithUnsignedExponent(abs(x), abs(n));
        if (!x_pos && n % 2 == 1) res = -res;
        if (n_pos) return res;
        else return 1 / res;

    }

    double powerWithUnsignedExponent(double base, unsigned int exponent) {
        if (exponent == 0) return 1;
        if (exponent == 1) return base;

        double result = powerWithUnsignedExponent(base, exponent >> 1);
        result *= result;
        if (exponent & 0x1 == 1) result *= base;
        return result;
    }
};


class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        double res = 1;
        long b = n;
        if (b < 0) {
            x = 1 / x;
            b = -b;
        }
        while (b) {
            if (b & 1 == 1) res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
    }
};