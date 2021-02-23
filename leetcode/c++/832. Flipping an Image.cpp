// 二次遍历
// 时间复杂度：O(nm)
// 空间复杂度：O(1)
class Solution {
public:
    vector <vector<int>> flipAndInvertImage(vector <vector<int>> &A) {
        int n = A.size();
        int m = A[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                int tmp = A[i][j];
                A[i][j] = A[i][m - j - 1];
                A[i][m - j - 1] = tmp;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                A[i][j] = A[i][j] == 0 ? 1 : 0;
            }
        }

        return A;
    }
};

// 一次遍历
// 时间复杂度：O(nm)
// 空间复杂度：O(1)
class Solution {
public:
    vector <vector<int>> flipAndInvertImage(vector <vector<int>> &A) {
        int n = A.size();
        int m = A[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                int tmp = A[i][j];
                A[i][j] = A[i][m - j - 1] == 1 ? 0 : 1;
                A[i][m - j - 1] = tmp == 1 ? 0 : 1;
            }
            if (m % 2 == 1) {
                A[i][m / 2] = A[i][m / 2] == 1 ? 0 : 1;
            }
        }
        return A;
    }
};