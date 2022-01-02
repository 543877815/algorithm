// 前缀和+单调栈
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int>> left(n, vector<int>(m, 0));
        // left[i][j] 表示前缀和
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0) ? 1 : left[i][j-1] + 1;
                }
            }
        }
        int res = 0;
        for (int j = 0; j < m; j++) {
            vector<int> up(n, 0), down(n, n);
            stack<int> stk;
            for (int i = 0; i < n; i++) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    down[stk.top()] = i;
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
            for (int i = 0; i < n; i++) {
                res = max(res, (down[i] - up[i] - 1) * left[i][j]);
            }
        }
        return res;
    }
};