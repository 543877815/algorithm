// 时间复杂度：O(mnl)
// 空间复杂度：O(mn)
class Solution {
public:
    int findMaxForm(vector <string> &strs, int m, int n) {
        int len = strs.size();
        if (len == 0) return 0;
        vector<int> ones(len, 0);
        vector<int> zeros(len, 0);

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0') zeros[i]++;
                else if (strs[i][j] == '1') ones[i]++;
            }
        }
        // dp[i][j]表示i个0和j个1能选择的最大元素个数
        vector <vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 0;
        for (int k = 0; k < len; k++) {
            for (int i = m; i >= 0; i--) {
                for (int j = n; j >= 0; j--) {
                    if (i >= zeros[k] && j >= ones[k]) {
                        dp[i][j] = max(dp[i][j], dp[i - zeros[k]][j - ones[k]] + 1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};