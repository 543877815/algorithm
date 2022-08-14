class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res = vector<vector<int>>(n - 2, vector<int>(n - 2));

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                for (int p = -1; p <= 1; p++) {
                    for (int q = -1; q <= 1; q++) {
                        res[i-1][j-1] = max(res[i-1][j-1], grid[i+p][j+q]);
                    }
                }
            }
        }

        return res;
    }
};