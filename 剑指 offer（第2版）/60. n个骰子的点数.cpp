// 动态规划
// 时间复杂度：O(6n^2)
// 空间复杂度：O(6n)
class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> dp;
        if (n <= 0) return dp;
        dp = vector<double>(6 * n + 1, 0);
        for (int i = 1; i <= 6; i++) dp[i] = 1;
        for (int i = 2; i <= n; i++) { // 骰子个数
            for (int j = i * 6; j >= i; j--) { // 旧的筛子
                double sum = 0;
                for (int k = 1; k <= 6; k++) { // 新的筛子
                    if (j - k >= i - 1) sum += dp[j - k];
                    else break;
                }
                dp[j] = sum;
            }
        }
        for (double &i : dp) {
            i /= (pow(6, n));
        }
        vector<double> res(dp.begin() + n, dp.end());
        return res;
    }
};