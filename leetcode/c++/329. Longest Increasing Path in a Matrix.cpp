// 有记忆的深度优先搜索
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:

    int dp[4][2] = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
    };
    int n, m;
    bool isArea(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>> &visited, int x, int y) {
        if (visited[x][y] != 0) {
            return visited[x][y];
        }
        visited[x][y]++;
        for (int i = 0; i < 4; i++) {
            int new_x = x + dp[i][0];
            int new_y = y + dp[i][1];a
            if (isArea(new_x, new_y, n, m) && matrix[new_x][new_y] > matrix[x][y]) {
                visited[x][y] = max(visited[x][y], dfs(matrix, visited, new_x, new_y) + 1);
            }
        }

        return visited[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if (n == 0) return 0;
        m = matrix[0].size();
        if (m == 0) return 0;
        int res = 1;
        vector<vector<int>>visited (n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, dfs(matrix, visited, i, j));
            }
        }

        return res;
    }
};