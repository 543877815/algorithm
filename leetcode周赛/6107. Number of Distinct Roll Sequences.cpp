// 动态规划
// 时间复杂度：O(nm^2)
// 空间复杂度：O(nm^3)
class Solution {
    const int MOD = 1000000007;

public:
    int distinctSequences(int n) {
        int G[7][7] = {0};
        for (int i = 1; i <= 6; i++)
            for (int j = 1; j <= 6; j++)
                G[i][j] = __gcd(i, j);

        // 特殊情况。
        if (n == 1) return 6;
        else if (n == 2) {
            int ans = 0;
            for (int i = 1; i <= 6; i++)
                for (int j = 1; j <= 6; j++)
                    if (i != j && G[i][j] == 1) ans++;
            return ans;
        }

        // 每组数据都会创建 Solution 对象，但所有测试运行在同一进程中。
        // static 数组每个进程只会初始化一次，防止超时。
        static long long f[10010][7][7];

        // 清理要用到的数组下标。
        for (int t = 1; t <= n; t++)
            for (int i = 1; i <= 6; i++)
                for (int j = 1; j <= 6; j++)
                    f[t][i][j] = 0;

        // 计算初值。
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

        // 统计最终答案。
        long long ans = 0;
        for (int i = 1; i <= 6; i++)
            for (int j = 1; j <= 6; j++)
                ans = (ans + f[n][i][j]) % MOD;

        return ans;
    }
};