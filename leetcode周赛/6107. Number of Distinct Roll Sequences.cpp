// ��̬�滮
// ʱ�临�Ӷȣ�O(nm^2)
// �ռ临�Ӷȣ�O(nm^3)
class Solution {
    const int MOD = 1000000007;

public:
    int distinctSequences(int n) {
        int G[7][7] = {0};
        for (int i = 1; i <= 6; i++)
            for (int j = 1; j <= 6; j++)
                G[i][j] = __gcd(i, j);

        // ���������
        if (n == 1) return 6;
        else if (n == 2) {
            int ans = 0;
            for (int i = 1; i <= 6; i++)
                for (int j = 1; j <= 6; j++)
                    if (i != j && G[i][j] == 1) ans++;
            return ans;
        }

        // ÿ�����ݶ��ᴴ�� Solution ���󣬵����в���������ͬһ�����С�
        // static ����ÿ������ֻ���ʼ��һ�Σ���ֹ��ʱ��
        static long long f[10010][7][7];

        // ����Ҫ�õ��������±ꡣ
        for (int t = 1; t <= n; t++)
            for (int i = 1; i <= 6; i++)
                for (int j = 1; j <= 6; j++)
                    f[t][i][j] = 0;

        // �����ֵ��
        for (int i = 1; i <= 6; i++)
            for (int j = 1; j <= 6; j++)
                for (int k = 1; k <= 6; k++)
                    if (i != j && i != k && j != k && G[i][j] == 1 && G[j][k] == 1)
                        f[3][i][j]++;

        // f(i, a, b) <- f(i - 1, b, c)
        for (int i = 4; i <= n; i++)
            for (int a = 1; a <= 6; a++)
                for (int b = 1; b <= 6; b++)
                    for (int c = 1; c <= 6; c++)
                        if (a != b && a != c && b != c && G[a][b] == 1 && G[b][c] == 1)
                            f[i][a][b] = (f[i][a][b] + f[i - 1][b][c]) % MOD;

        // ͳ�����մ𰸡�
        long long ans = 0;
        for (int i = 1; i <= 6; i++)
            for (int j = 1; j <= 6; j++)
                ans = (ans + f[n][i][j]) % MOD;

        return ans;
    }
};