// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0);
        for (int i = 2; i < n / 2; i++) {
            for (int j = 1; i * j <= n; j++) {
                if ((i * j) % 2 == 0) {
                    dp[i * j] = min(dp[i * j], 2 + dp[i * j / 2]);
                } else {
                    dp[i * j] = min(dp[i * j], j + dp[i]);
                }

            }
        }
        dp[1] = 0;
        return dp[n];
    }
};

// 素数分解
// 时间复杂度：O(sqrt(N))
// 空间复杂度：O(1)
class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        // i=2 是最小的素数
        for (int i = 2; i <= n; i++) {
            // 如果是最小的素数则持续操作
            while (n % i == 0) {
                // 如果是素数则计算次数
                res += i;
                n /= i;
            }
        }
        return res;
    }
};