// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int checkRecord(int n) {
        // dp[i][j][k]表示前i天有j个A且结尾有k个连续L的可奖励的出勤记录的数量，j<=1,k<=2
        vector < vector < vector < int>>> dp = vector < vector < vector < int>>>(n + 1, vector < vector <
                                                                                        int >> (2, vector<int>(3)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            // dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]) % MOD;  // 新的字母必须是P
            for (int k = 0; k <= 2; k++) {
                dp[i][0][0] = (dp[i][0][0] + dp[i - 1][0][k]) % MOD;  // 新的字母必须是P
            }
            dp[i][0][1] = dp[i - 1][0][0];   // 新的字母必须是L
            dp[i][0][2] = dp[i - 1][0][1];   // 新的字母必须是L

            // dp[i][1][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2] + dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2]) % MOD;
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 2; k++) {
                    dp[i][1][0] = (dp[i][1][0] + dp[i - 1][j][k]) % MOD;  // 新的字母是A或者P
                }
            }
            dp[i][1][1] = dp[i - 1][1][0];   // 新的字母必须是L
            dp[i][1][2] = dp[i - 1][1][1];   // 新的字母必须是L
        }
        int res = 0;
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 2; k++) {
                res = (res + dp[n][j][k]) % MOD;
            }
        }
        return res;
    }
};

// 状态压缩
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int checkRecord(int n) {
        // dp[i][j][k]表示前i天有j个A且结尾有k个连续L的可奖励的出勤记录的数量，j<=1,k<=2
        vector <vector<int>> prev = vector < vector < int >> (2, vector<int>(3));

        prev[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            vector <vector<int>> curr = vector < vector < int >> (2, vector<int>(3));

            for (int k = 0; k <= 2; k++) {
                curr[0][0] = (curr[0][0] + prev[0][k]) % MOD;  // 新的字母必须是P
            }
            curr[0][1] = prev[0][0];   // 新的字母必须是L
            curr[0][2] = prev[0][1];   // 新的字母必须是L
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 2; k++) {
                    curr[1][0] = (curr[1][0] + prev[j][k]) % MOD;  // 新的字母是A或者P
                }
            }
            curr[1][1] = prev[1][0];   // 新的字母必须是L
            curr[1][2] = prev[1][1];   // 新的字母必须是L

            prev = curr;
        }

        int res = 0;
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 2; k++) {
                res = (res + prev[j][k]) % MOD;
            }
        }
        return res;
    }
};


class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int checkRecord(int n) {
        int dp[2][3];  // A 的数量，结尾连续 L 的数量
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int dpNew[2][3];  // A 的数量，结尾连续 L 的数量
            memset(dpNew, 0, sizeof(dpNew));
            // 以 P 结尾的数量
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 2; k++) {
                    dpNew[j][0] = (dpNew[j][0] + dp[j][k]) % MOD;
                }
            }
            // 以 A 结尾的数量
            for (int k = 0; k <= 2; k++) {
                dpNew[1][0] = (dpNew[1][0] + dp[0][k]) % MOD;
            }
            // 以 L 结尾的数量
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= 2; k++) {
                    dpNew[j][k] = (dpNew[j][k] + dp[j][k - 1]) % MOD;
                }
            }
            memcpy(dp, dpNew, sizeof(dp));
        }
        int sum = 0;
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 2; k++) {
                sum = (sum + dp[j][k]) % MOD;
            }
        }
        return sum;
    }
};

