// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int length = matrix.size() - 1;
        for (int i = 0; i < matrix.size() / 2; i++) {
            for (int j = i; j < matrix.size() - i - 1; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[length - j][i];
                matrix[length - j][i] = matrix[length - i][length - j];
                matrix[length - i][length - j] = matrix[j][length - i];
                matrix[j][length - i] = tmp;
            }
        }
    }
};