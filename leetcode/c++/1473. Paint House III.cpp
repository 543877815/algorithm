// 动态规划
// 时间复杂度：O(mn^2k)
// 空间复杂度：O(mnk)
class Solution {
private:
    static constexpr int INFTY = INT_MAX / 2;
public:
    int minCost(vector<int> &houses, vector <vector<int>> &cost, int m, int n, int target) {
        // 将颜色调整为从 0 开始编号，没有被涂色的标记为—-1
        for (int &c : houses) c--;

        // dp 所有元素初始化为极大值
        vector < vector < vector < int>>> dp(m, vector < vector < int >> (n, vector<int>(target, INFTY)));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (houses[i] != -1 && houses[i] != j) continue;

                for (int k = 0; k < target; k++) {
                    for (int j0 = 0; j0 < n; j0++) {
                        if (j == j0) {
                            if (i == 0) {
                                if (k == 0) {
                                    dp[i][j][k] = 0;
                                }
                            } else {
                                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                            }
                        } else if (i > 0 && k > 0) {
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j0][k - 1]);
                        }
                    }

                    if (dp[i][j][k] != INFTY && houses[i] == -1) {
                        dp[i][j][k] += cost[i][j];
                    }
                }
            }
        }
        int ans = INFTY;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[m - 1][j][target - 1]);
        }
        return ans == INFTY ? -1 : ans;
    }
};


// 动态规划+优化
// 时间复杂度：O(mnk)
// 空间复杂度：O(mnk)
class Solution {
private:
    // 极大值
    // 选择 INT_MAX / 2 的原因是防止整数相加溢出
    static constexpr int INFTY = INT_MAX / 2;

    using TIII = tuple<int, int, int>;

public:
    int minCost(vector<int> &houses, vector <vector<int>> &cost, int m, int n, int target) {
        // 将颜色调整为从 0 开始编号，没有被涂色标记为 -1
        for (int &c: houses) {
            --c;
        }

        // dp 所有元素初始化为极大值
        vector < vector < vector < int>>> dp(m, vector < vector < int >> (n, vector<int>(target, INFTY)));
        vector <vector<TIII>> best(m, vector<TIII>(target, {INFTY, -1, INFTY}));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (houses[i] != -1 && houses[i] != j) {
                    continue;
                }

                for (int k = 0; k < target; ++k) {
                    if (i == 0) {
                        if (k == 0) {
                            dp[i][j][k] = 0;
                        }
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                        if (k > 0) {
                            // 使用 best(i-1,k-1) 直接得到 dp(i,j,k) 的值
                            auto&&[first, first_idx, second] = best[i - 1][k - 1];
                            dp[i][j][k] = min(dp[i][j][k], (j == first_idx ? second : first));
                        }
                    }

                    if (dp[i][j][k] != INFTY && houses[i] == -1) {
                        dp[i][j][k] += cost[i][j];
                    }

                    // 用 dp(i,j,k) 更新 best(i,k)
                    auto&&[first, first_idx, second] = best[i][k];
                    if (dp[i][j][k] < first) {
                        second = first;
                        first = dp[i][j][k];
                        first_idx = j;
                    } else if (dp[i][j][k] < second) {
                        second = dp[i][j][k];
                    }
                }
            }
        }

        int ans = INFTY;
        for (int j = 0; j < n; ++j) {
            ans = min(ans, dp[m - 1][j][target - 1]);
        }
        return ans == INFTY ? -1 : ans;
    }
};
