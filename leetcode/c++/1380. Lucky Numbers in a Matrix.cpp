// 时间复杂度：O(nm)
// 空间复杂度：O(n+m)
class Solution {
public:
    vector<int> luckyNumbers(vector <vector<int>> &matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        if (n == 0) return res;

        vector<int> row;
        for (int i = 0; i < m; i++) {
            int MIN = INT_MAX;
            for (int j = 0; j < n; j++) {
                MIN = min(MIN, matrix[i][j]);
            }
            row.push_back(MIN);
        }

        vector<int> col;
        for (int i = 0; i < n; i++) {
            int MAX = INT_MIN;
            for (int j = 0; j < m; j++) {
                MAX = max(MAX, matrix[j][i]);
            }
            col.push_back(MAX);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == col[j])
                    res.push_back(row[i]);
            }
        }

        return res;
    }
};