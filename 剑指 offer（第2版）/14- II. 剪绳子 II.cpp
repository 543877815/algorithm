// 时间复杂度：O(logk)
// 空间复杂度：O(1)
class Solution {
private:
    // a ^ b % c
    int powerMod(long long a, long long b, long long c, long long res) {
        while (b > 0) {
            if (b % 2 == 1) res = (res * a) % c;
            a = a * a % c;
            b /= 2;
        }
        return (int) res;
    }

public:
    int cuttingRope(int n) {
        if (n < 2) return 0;
        if (n == 2) return 1;
        if (n == 3) return 2;

        int timesOf3 = n / 3;

        if (n - timesOf3 * 3 == 1) timesOf3--;
        int timesOf2 = (n - timesOf3 * 3) / 2;

        int mod = 1000000007;

        int powerOf2 = powerMod(2, timesOf2, mod, 1);

        return powerMod(3, timesOf3, mod, powerOf2);

    }
};