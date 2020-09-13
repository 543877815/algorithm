// DFS
// 时间复杂度：O(n+m)
// 空间复杂度：O(nm)
class Solution {
public:
    int m, n;
    int d[2][2] = {
            {0, 1},
            {1, 0},
    };

    vector <vector<bool>> visited;

    bool isArea(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    void DFS(vector <vector<int>> &obstacleGrid, vector <vector<int>> &res, int x, int y) {
        res.push_back({x, y});
        if (x == m - 1 && y == n - 1) return;
        for (int i = 0; i < 2; i++) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if (isArea(newx, newy) && !visited[newx][newy] && obstacleGrid[newx][newy] != 1) {
                visited[newx][newy] = true;
                DFS(obstacleGrid, res, newx, newy);
                if (res.back()[0] == m - 1 && res.back()[1] == n - 1) return;
            }
        }
        res.pop_back();
    }

    vector <vector<int>> pathWithObstacles(vector <vector<int>> &obstacleGrid) {
        vector <vector<int>> res;
        m = obstacleGrid.size();
        if (m == 0) return res;
        n = obstacleGrid[0].size();
        if (n == 0) return res;
        visited = vector < vector < bool >> (m, vector<bool>(n, false));
        visited[0][0] = true;
        if (obstacleGrid[0][0] == 1) return res;
        else DFS(obstacleGrid, res, 0, 0);
        return res;
    }
};