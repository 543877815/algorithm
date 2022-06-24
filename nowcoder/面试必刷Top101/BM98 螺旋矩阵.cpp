class Solution {
public:
    vector<int> spiralOrder(vector <vector<int>> &matrix) {
        vector<int> res;
        int n = matrix.size();
        if (n == 0) return res;
        int m = matrix[0].size();
        if (m == 0) return res;
        int left = 0, right = m - 1, up = 0, down = n - 1;
        int i = 0, j = 0;
        int arrow = 1;  // 1 = right, 2 = down, 3 = left, 4 = up
        while (res.size() < n * m) {

            if (arrow == 1) {
                while (j <= right) {
                    res.push_back(matrix[i][j]);
                    j++;
                }
                up++;
                i++;
                j--;
                arrow = 2;
            } else if (arrow == 2) {
                while (i <= down) {
                    res.push_back(matrix[i][j]);
                    i++;
                }
                right--;
                j--;
                i--;
                arrow = 3;
            } else if (arrow == 3) {
                while (j >= left) {
                    res.push_back(matrix[i][j]);
                    j--;
                }
                down--;
                i--;
                j++;
                arrow = 4;
            } else if (arrow == 4) {
                while (i >= up) {
                    res.push_back(matrix[i][j]);
                    i--;
                }
                left++;
                j++;
                i++;
                arrow = 1;
            }
        }

        return res;
    }
};