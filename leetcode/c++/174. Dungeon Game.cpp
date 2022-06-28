// 动态规划
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    int calculateMinimumHP(vector <vector<int>> &dungeon) {
        int n = dungeon.size();
        if (n == 0) return 0;
        int m = dungeon[0].size();
        if (m == 0) return 0;
        vector <vector<int>> dp(n, vector<int>(m, 0));
        dp[n - 1][m - 1] = dungeon[n - 1][m - 1] >= 0 ? 1 : abs(dungeon[n - 1][m - 1]) + 1;
        for (int i = n - 2; i >= 0; i--) {
            int tmp = dp[i + 1][m - 1] - dungeon[i][m - 1];
            dp[i][m - 1] = tmp > 0 ? abs(tmp) : 1;

        }

        for (int j = m - 2; j >= 0; j--) {
            int tmp = dp[n - 1][j + 1] - dungeon[n - 1][j];
            dp[n - 1][j] = tmp > 0 ? abs(tmp) : 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                int tmp = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = tmp > 0 ? abs(tmp) : 1;
            }
        }

        return dp[0][0] > 0 ? dp[0][0] : 1;
    }
};