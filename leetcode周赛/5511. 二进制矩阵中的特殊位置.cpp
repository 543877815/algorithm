// 时间复杂度：O(nm)
// 空间复杂度：O(n+m)
class Solution {
public:
    int numSpecial(vector <vector<int>> &mat) {
        int m = mat.size();
        if (m == 0) return 0;
        int n = mat[0].size();
        if (n == 0) return 0;
        vector<bool> row(m, true);
        vector<bool> col(n, true);
        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) count++;
            }
            if (count >= 2) row[i] = false;
        }

        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][j] == 1) count++;
            }
            if (count >= 2) col[j] = false;
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            if (row[i] == false) continue;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && row[i] == true && col[j] == true) res++;
            }
        }

        return res;
    }
};