// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    const int MODULO = 1000000007;

    int numWays(int steps, int arrLen) {
        // dp[i][j] 表示在第 i 步操作之后，指针位于下标 j 的方案数
        int maxColumn = min(steps, arrLen - 1);
        // dp[0][0] 初始化为 1, dp[0][i] 初始化为 0
        vector <vector<int>> dp(steps + 1, vector<int>(maxColumn + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= maxColumn; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MODULO;
                if (j + 1 <= maxColumn) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MODULO;
            }
        }
        return dp[steps][0];
    }
};

// 空间优化
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    const int MODULO = 1000000007;

    int numWays(int steps, int arrLen) {
        // dp[i]指针位于下标 i 的方案数
        int maxColumn = min(steps, arrLen - 1);
        // dp[0] 初始化为 1, dp[i] 初始化为 0
        vector<int> dp(maxColumn + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= steps; i++) {
            vector<int> dpNext(maxColumn + 1);
            for (int j = 0; j <= maxColumn; j++) {
                dpNext[j] = dp[j];
                if (j - 1 >= 0) dpNext[j] = (dpNext[j] + dp[j - 1]) % MODULO;
                if (j + 1 <= maxColumn) dpNext[j] = (dpNext[j] + dp[j + 1]) % MODULO;
            }
            dp = dpNext;
        }
        return dp[0];
    }
};