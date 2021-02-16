// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    vector <vector<int>> matrixReshape(vector <vector<int>> &nums, int r, int c) {
        int n = nums.size();
        if (n == 0) return nums;
        int m = nums[0].size();
        if (m == 0) return nums;
        if (n * m != r * c) return nums;
        vector <vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int index = i * m + j;
                res[index / c][index % c] = nums[i][j];
            }
        }

        return res;
    }
};