// 前缀和
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class NumMatrix {
public:
    vector<vector<int>> presum;

    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        presum = vector<vector<int>> (n+1, vector<int>(m+1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                presum[i+1][j+1] = presum[i+1][j] + presum[i][j+1] - presum[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return presum[row2+1][col2+1] - presum[row2+1][col1] - presum[row1][col2+1] + presum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */