// 时间复杂度：O(nm)
// 空间复杂度：O(1)
class Solution {
public:
    bool isToeplitzMatrix(vector <vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int j = 1;
            int num = matrix[0][i];
            while (j < n && i + j < m) {
                if (num != matrix[j][i + j]) return false;
                j++;
            }
        }

        for (int i = 1; i < n; i++) {
            int j = 1;
            int num = matrix[i][0];
            while (i + j < n && j < m) {
                if (num != matrix[i + j][j]) return false;
                j++;
            }
        }

        return true;
    }
};