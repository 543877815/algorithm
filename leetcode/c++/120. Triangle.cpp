// 时间复杂度：O((1+n)n/2)
// 空间复杂度：O(n)
class Solution {
public:
    int minimumTotal(vector <vector<int>> &triangle) {
        int n = triangle.size();
        if (!n) return 0;
        vector<int> dp = vector<int>(n, INT_MAX);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (j == 0) {
                    dp[j] = dp[j] + triangle[i][j];
                } else {
                    dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
                }
            }
        }
        int num = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (num > dp[i]) num = dp[i];
        }
        return num;
    }
};