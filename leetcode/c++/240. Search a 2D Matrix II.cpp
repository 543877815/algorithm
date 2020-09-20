// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int column = matrix[0].size() - 1;
        int row = 0;
        while(column >= 0 && row < matrix.size()) {
            if (matrix[row][column] == target) return true;
            else if (matrix[row][column] > target) column--;
            else row ++;
        }
        return false;
    }
};