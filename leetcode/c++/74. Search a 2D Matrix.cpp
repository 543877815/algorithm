// 遍历
// 时间复杂度：O(n+m)
// 空间复杂度：O(n)
class Solution {
public:
    bool searchMatrix(vector <vector<int>> &matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        int i;
        for (i = 0; i < n; i++) {
            if (matrix[i][0] > target) break;
        }
        if (i == 0) return false;
        for (int j = 0; j < m; j++) {
            if (matrix[i - 1][j] == target) return true;
            if (matrix[i - 1][j] > target) return false;
        }
        return false;
    }
};