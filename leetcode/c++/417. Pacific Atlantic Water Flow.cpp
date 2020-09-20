// 回溯，深度优先搜索
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
private:
    int d[4][2] = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1}};
    vector <vector<int>> res;
    int n, m;
    bool left_up;
    bool right_down;
    vector <vector<bool>> visited;

    bool isArea(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    void DFS(vector <vector<int>> &matrix, int x, int y) {
        if (x == 0 || y == 0) left_up = true;
        if (x == n - 1 || y == m - 1) right_down = true;
        if (left_up && right_down) return;

        for (int i = 0; i < 4; i++) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if (isArea(newx, newy) && !visited[newx][newy] && matrix[x][y] >= matrix[newx][newy]) {
                visited[x][y] = true;
                DFS(matrix, newx, newy);
                visited[x][y] = false;
            }
        }
    }

public:
    vector <vector<int>> pacificAtlantic(vector <vector<int>> &matrix) {
        n = matrix.size();
        if (n == 0) return res;
        m = matrix[0].size();
        if (m == 0) return res;
        visited = vector < vector < bool >> (n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                left_up = false;
                right_down = false;
                DFS(matrix, i, j);
                if (left_up && right_down)
                    res.push_back({i, j});
            }
        }

        return res;
    }
};