// 时间复杂度：O(nm)
// 空间复杂度：O(n+m)
class Solution {
public:
    void setZeroes(vector <vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> row(n, true);
        vector<bool> col(m, true);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = false;
                    col[j] = false;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (row[i] == false) {
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < m; j++) {
            if (col[j] == false) {
                for (int i = 0; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};