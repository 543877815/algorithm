// 动态规划
// 时间复杂度：O(n * n * k)
// 空间复杂度：O(n^2)
class Solution {
public:
    bool isArea(int n, int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }

    double knightProbability(int n, int k, int row, int column) {
        int directors[8][2] = {
                {1,  2},
                {2,  1},
                {1,  -2},
                {2,  -1},
                {-1, 2},
                {-2, 1},
                {-1, -2},
                {-2, -1}
        };
        vector <vector<double>> pre = vector < vector < double >> (n, vector<double>(n, 0));
        pre[row][column] = 1;
        double res = 0;
        for (int i = 0; i < k; i++) {
            vector <vector<double>> curr = vector < vector < double >> (n, vector<double>(n, 0));
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    for (int j = 0; j < 8; j++) {
                        int new_x = x + directors[j][0];
                        int new_y = y + directors[j][1];
                        if (isArea(n, new_x, new_y)) {
                            curr[new_x][new_y] = (curr[new_x][new_y] + pre[x][y] / 8);
                        }
                    }
                }
            }
            pre = curr;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += pre[i][j];
            }
        }
        return res;
    }
};