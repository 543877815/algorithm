// ʱ�临�Ӷȣ�O(n^2)
// �ռ临�ӵģ�O(n^2)
class Solution {
public:
    vector <vector<int>> rotateMatrix(vector <vector<int>> mat, int n) {
        // write code here
        vector <vector<int>> res(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int i = n - 1; i >= 0; i--) {
                res[j][n - 1 - i] = mat[i][j];
            }
        }

        return res;
    }
};

// ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷȣ�O(1)
class Solution {
public:
    vector <vector<int>> rotateMatrix(vector <vector<int>> mat, int n) {
        //�Ȱ����Խ��߷�ת�������ҷ�ת
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int tmp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = tmp;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int tmp = mat[i][(n - 1) - j];
                mat[i][(n - 1) - j] = mat[i][j];
                mat[i][j] = tmp;
            }
        }
        return mat;
    }
};