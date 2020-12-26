// 单调栈
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    int maximalSquare(vector <vector<char>> &matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector <vector<int>> left(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0) ? 1 : left[i][j - 1] + 1;
                }
            }
        }

        int res = 0;
        for (int j = 0; j < n; j++) {
            vector<int> up(m, 0), down(m, m);
            stack<int> stk;
            for (int i = 0; i < m; i++) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    down[stk.top()] = i;
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }

            for (int i = 0; i < m; i++) {
                int side = min(left[i][j], down[i] - up[i] - 1);
                res = max(res, side * side);
            }
        }
        return res;
    }
};

// 动态规划
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    int maximalSquare(vector <vector<char>> &matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        vector <vector<int>> dp(m, vector<int>(n, 0));
        int maxSize = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    maxSize = max(maxSize, dp[i][j]);
                }
            }
        }
        return maxSize * maxSize;

    }
};