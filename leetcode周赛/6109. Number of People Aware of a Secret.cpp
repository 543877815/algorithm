// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
// 直接模拟
class Solution {
public:
    const int MOD = 1000000007;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> current(n + 1, 0);
        vector<long long> in(n + 1, 0);
        vector<long long> out(n + 1, 0);
        current[1] = 1;
        in[1] = 1;

        for (int i = 2; i <= n; i++) {
            current[i] = current[i - 1];
            if (i - forget >= 1) {
                out[i] = in[i - forget];
                current[i] = (current[i] - out[i] + MOD) % MOD;
            }
            if (i - delay >= 1) {
                in[i] = current[i - delay];
                if (i - forget >= 1) {
                    for (int j = i - delay + 1; j <= i; j++) {
                        in[i] = (in[i] - out[j]) % MOD;
                    }
                    in[i] = (in[i] + MOD) % MOD;
                }
                current[i] = (current[i] + in[i]) % MOD;
            }
        }

        return current[n] % MOD;
    }
};


// 题解一
// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    const int MOD = 1e9 + 7;

    // A类知道秘密，但不能分享
    // B类知道秘密，可以分享
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n, 0);  // 第i天B类人的人数
        dp[0] = 1;
        int cnt_a = 0;
        for (int i = 0; i < n; i++) {
            if (i + delay >= n) cnt_a = (cnt_a + dp[i]) % MOD;
            for (int j = i + delay; j < min(i + forget, n); j++) {
                dp[j] = (dp[j] + dp[i]) % MOD;
            }
        }
        return (cnt_a + dp[n - 1]) % MOD;
    }
};


// 题解二
// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    const int MOD = 1e9 + 7;

    // A类知道秘密，但不能分享
    // B类知道秘密，可以分享
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> sum(n + 1, 0);
        sum[0] = 0;
        sum[1] = 1;
        for (int i = 2; i <= n; i++) {
            // f[i] 定义成第 i 天新增的知道秘密的人数
            int f = (sum[max(i - delay, 0)] - sum[max(i - forget, 0)]) % MOD;
            sum[i] = (sum[i - 1] + f) % MOD;
        }

        return ((sum[n] - sum[max(n - forget, 0)]) % MOD + MOD) % MOD; // 防止结果为负数
    }
};