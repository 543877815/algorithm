// 快速幂取余
// 时间复杂度：O(\sum_{i=0)^(m-1) log b_i
// 空间复杂度：O(1)
class Solution {
public:
    const int MOD = 1337;

    int pow(int a, int b) {
        long long res = 1;
        while (b > 0) {
            if (b % 2 == 1) res = (res * a) % MOD;
            a = (long) a * a % MOD;
            b /= 2;
        }
        return (int) res;
    }

    int superPow(int a, vector<int> &b) {
        int n = b.size();
        long long res = 1;
        for (int i = n - 1; i >= 0; i--) {
            res = res * pow(a, b[i]) % MOD;
            a = pow(a, 10);
        }

        return (int) res;
    }
};


// 正序遍历
// 时间复杂度：O(\sum_{i=0)^(m-1) log b_i
// 空间复杂度：O(1)
class Solution {
public:
    const int MOD = 1337;

    int pow(int a, int b) {
        long long res = 1;
        while (b > 0) {
            if (b % 2 == 1) res = (res * a) % MOD;
            a = (long) a * a % MOD;
            b /= 2;
        }
        return (int) res;
    }

    int superPow(int a, vector<int>& b) {
        int n = b.size();
        long long res = 1;
        for (int i = 0; i < n; i++) {
            res = pow(res, 10) * pow(a, b[i]) % MOD;
        }
        return (int) res;
    }
};