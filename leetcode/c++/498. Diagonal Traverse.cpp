// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    vector<int> findDiagonalOrder(vector <vector<int>> &mat) {
        vector<int> res;
        int n = mat.size();
        if (n == 0) return res;
        int m = mat[0].size();
        if (m == 0) return res;
        map<int, vector<int>> record;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                record[i + j].push_back(mat[i][j]);
            }
        }

        for (auto &[key, value]: record) {
            if (key % 2 == 1) {
                for (int i = 0; i < value.size(); i++) {
                    res.push_back(value[i]);
                }
            } else {
                for (int i = value.size() - 1; i >= 0; i--) {
                    res.push_back(value[i]);
                }
            }
        }

        return res;
    }
};

// 模拟
// 时间复杂度：O(mxn)
// 空间复杂度：O(1)
class Solution {
public:
    vector<int> findDiagonalOrder(vector <vector<int>> &mat) {
        vector<int> res;
        int m = mat.size();
        if (m == 0) return res;
        int n = mat[0].size();
        if (n == 0) return res;
        for (int i = 0; i < m + n - 1; i++) {
            if (i % 2) {
                int x = i < n ? 0 : i - n + 1;
                int y = i < n ? i : n - 1;
                while (x < m && y >= 0) {
                    res.push_back(mat[x][y]);
                    x++;
                    y--;
                }
            } else {
                int x = i < m ? i : m - 1;
                int y = i < m ? 0 : i - m + 1;
                while (x >= 0 && y < n) {
                    res.push_back(mat[x][y]);
                    x--;
                    y++;
                }
            }
        }
        return res;
    }
};