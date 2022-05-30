// 时间复杂度：O(2^(n+m))
// 空间复杂度：O(n+m)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    const int directions[4][2] = {
            {0,  1},
            {0,  -1},
            {-1, 0},
            {1,  0}
    };

    int res = 1;
    vector <vector<bool>> used;

    bool isArea(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    void dfs(int x, int y, int curr, vector <vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        res = max(res, curr);
        for (int i = 0; i < 4; i++) {
            int new_x = x + directions[i][0];
            int new_y = y + directions[i][1];
            if (isArea(new_x, new_y, n, m) && !used[new_x][new_y] && matrix[new_x][new_y] > matrix[x][y]) {
                used[new_x][new_y] = true;
                dfs(new_x, new_y, curr + 1, matrix);
                used[new_x][new_y] = false;
            }
        }
    }

    int solve(vector <vector<int>> &matrix) {
        // write code here
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        used = vector < vector < bool >> (n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(i, j, 1, matrix);
            }
        }

        return res;
    }
};