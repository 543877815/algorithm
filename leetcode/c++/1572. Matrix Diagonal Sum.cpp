// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int diagonalSum(vector <vector<int>> &mat) {
        int size = mat.size();
        int sum = 0;
        for (int i = 0; i < size; i++) sum += mat[i][i];
        for (int i = 0; i < size; i++) sum += mat[i][size - 1 - i];
        if (size % 2 == 1) sum -= mat[size / 2][size / 2];
        return sum;
    }
};