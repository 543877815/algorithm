// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    int oddCells(int m, int n, vector <vector<int>> &indices) {
        vector <vector<int>> dp(m, vector<int>(n, 0));
        int p = indices.size();
        for (int i = 0; i < p; i++) {
            int row = indices[i][0], col = indices[i][1];
            for (int j = 0; j < n; j++) {
                dp[row][j]++;
            }
            for (int j = 0; j < m; j++) {
                dp[j][col]++;
            }
        }


        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] % 2 == 1) {
                    res++;
                }
            }
        }

        return res;
    }
};