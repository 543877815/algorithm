// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    const int MOD = 1000000007;

    long long factorial(int n) {
        if (n == 1) return 1;
        return n * factorial(n - 1) % MOD;
    }

    int numPrimeArrangements(int n) {
        if (n == 1) return 1;
        vector<bool> isPrime(n + 1, true);
        isPrime[1] = false;
        for (int i = 2; i <= n; i++) {
            for (int j = 2; i * j <= n; j++) {
                isPrime[i * j] = false;
            }
        }
        int prime_num = 0;
        for (int i = 1; i <= n; i++) {
            if (isPrime[i]) prime_num++;
        }
        return ((factorial(prime_num) % MOD) * (factorial(n - prime_num) % MOD)) % MOD;
    }
};