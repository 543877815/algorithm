// 动态规划
// 时间复杂度：O(nm(n+m)
// 空间复杂度：O(nm)
class Solution {
public:
    long long sellingWood(int m, int n, vector <vector<int>> &prices) {
        // 定义 dp[i][j] 表示对一块高 i 宽 j 的木块，切割后能得到的最多钱数。
        int k = prices.size();
        vector <vector<int>> pr = vector < vector < int >> (m + 1, vector<int>(n + 1, 0));
        for (auto &price: prices) {
            pr[price[0]][price[1]] = price[2];
        }

        vector <vector<long>> dp = vector < vector < long >> (m + 1, vector<long>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = pr[i][j];
                for (int k = 1; k < i; k++) dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);  // 垂直切割
                for (int k = 1; k < j; k++) dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);  // 水平切割
            }
        }

        return dp[m][n];
    }
};