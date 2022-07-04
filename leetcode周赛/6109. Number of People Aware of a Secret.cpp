// ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷȣ�O(n)
// ֱ��ģ��
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


// ���һ
// ��̬�滮
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    const int MOD = 1e9 + 7;

    // A��֪�����ܣ������ܷ���
    // B��֪�����ܣ����Է���
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n, 0);  // ��i��B���˵�����
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


// ����
// ��̬�滮
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    const int MOD = 1e9 + 7;

    // A��֪�����ܣ������ܷ���
    // B��֪�����ܣ����Է���
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> sum(n + 1, 0);
        sum[0] = 0;
        sum[1] = 1;
        for (int i = 2; i <= n; i++) {
            // f[i] ����ɵ� i ��������֪�����ܵ�����
            int f = (sum[max(i - delay, 0)] - sum[max(i - forget, 0)]) % MOD;
            sum[i] = (sum[i - 1] + f) % MOD;
        }

        return ((sum[n] - sum[max(n - forget, 0)]) % MOD + MOD) % MOD; // ��ֹ���Ϊ����
    }
};