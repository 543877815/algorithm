// 前缀和
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class NumMatrix {
public:
    vector <vector<int>> sums;
    int n, m;

    NumMatrix(vector <vector<int>> &matrix) {
        n = matrix.size();
        if (n == 0) return;
        m = matrix[0].size();
        sums = vector < vector < int >> (n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1] - sums[row1][col2 + 1] + sums[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */