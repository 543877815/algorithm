// 空间复杂度：O(n^2)
// 时间复杂度：O(n^3)
class Solution {
public:
    int minScoreTriangulation(vector<int> &A) {
        int m = A.size() - 1;
        vector <vector<int>> dp(m + 1, vector<int>(m + 1, 0));  // dp 表示起点为 i, 终点为 j 的最低得分
        for (int r = 2; r <= m; r++) {  // r 从 2 到 size - 1 , 表示窗口大小
            for (int i = 1; i <= m - r + 1; i++) {  // i 从 1 到 size - 1, 表示起点
                int j = i + r - 1;   // j 从 2 到 size - 1, 表示终点
                dp[i][j] = dp[i + 1][j] + A[i - 1] * A[i] * A[j];
                for (int k = i + 1; k < j; k++) {  // k 从 i + 1 到 j - 1, 表示分割点
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + A[i - 1] * A[k] * A[j]);
                }
            }
        }
        return dp[1][m];
    }
};

// 空间复杂度：O(n^2)
// 时间复杂度：O(n^3)
class Solution {
public:
    int minScoreTriangulation(vector<int> &A) {
        int m = A.size();
        vector <vector<int>> dp(m, vector<int>(m, INT_MAX));          // dp 表示从起点0到终点i的最低得分，初始化为最大值
        for (int i = 0; i < m - 1; i++) dp[i][i + 1] = 0;              // 假设第三边为0, 临边初始化为0
        for (int r = 2; r < m; r++) {                                // r 从 2 到 m - 1, 表示窗口大小
            for (int i = 0; i < m - r; i++) {                        // 起点范围 从 0 到 m - 3
                int j = i + r;                                       // 终点范围 从 2 到 m - 1
                for (int k = i + 1; k < j; k++) {                    // 分割点从起点到终点之间找一个
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]);
                }
            }
        }
        return dp[0][m - 1];
    }
};