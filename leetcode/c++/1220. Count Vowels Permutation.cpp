// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    static constexpr int MOD = 1000000007;

    int countVowelPermutation(int n) {
        long long a = 1;
        long long e = 1;
        long long i = 1;
        long long o = 1;
        long long u = 1;

        for (int j = 1; j < n; j++) {
            long long new_a = (e + u + i) % MOD;
            long long new_e = (a + i) % MOD;
            long long new_i = (e + o) % MOD;
            long long new_o = i % MOD;
            long long new_u = (i + o) % MOD;

            a = new_a;
            e = new_e;
            i = new_i;
            o = new_o;
            u = new_u;
        }

        return (a + e + i + o + u) % MOD;
    }
};