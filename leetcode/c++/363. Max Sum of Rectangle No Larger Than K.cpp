// 有序集合
// 时间复杂度：O(m^2nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int maxSumSubmatrix(vector <vector<int>> &matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
        for (int i = 0; i < m; i++) { // 枚举上边界
            vector<int> sum(n);
            for (int j = i; j < m; j++) { // 枚举下边界
                for (int c = 0; c < n; c++) {
                    sum[c] += matrix[j][c]; // 更新每列的元素和
                }
                set<int> sumSet{0};
                int s = 0;
                for (int v : sum) {
                    s += v;
                    auto lb = sumSet.lower_bound(s - k);
                    if (lb != sumSet.end()) {
                        ans = max(ans, s - *lb);
                    }
                    sumSet.insert(s);
                }
            }
        }
        return ans;
    }
};

// 暴力枚举
// 空间复杂度：O(1)
// 时间复杂度：O(n^4)
class Solution {
public:
    int maxSumSubmatrix(vector <vector<int>> &matrix, int k) {
        vector <vector<int>> s(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + matrix[i][j];
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {

                for (int ii = 0; ii < i; ii++) {
                    for (int jj = 0; jj < j; jj++) {

                        int sum = s[i][j] - s[ii][j] - s[i][jj] + s[ii][jj];
                        if (sum <= k)ans = max(ans, sum);
                    }
                }
            }
        }

        return ans;
    }
};