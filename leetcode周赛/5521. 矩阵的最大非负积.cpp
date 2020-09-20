// DFS
class Solution {
private:
    int m, n;
    int dp[2][2] = {
            {1, 0},
            {0, 1}
    };

    bool isArea(int x, int y) {
        return x < m && x >= 0 && y < n && y >= 0;
    }

    long long maxTimes = INT_MIN;

    void DFS(vector <vector<int>> &grid, int x, int y, long long num) {
        if ((grid[x][y] == 0) || (x == m - 1 && y == n - 1)) {
            if (num > maxTimes && num >= 0) {
                maxTimes = num;
            }
            return;
        }

        for (int i = 0; i < 2; i++) {
            int newx = x + dp[i][0];
            int newy = y + dp[i][1];
            if (isArea(newx, newy)) {
                DFS(grid, newx, newy, num * grid[newx][newy]);
            }
        }
    }

public:
    int maxProductPath(vector <vector<int>> &grid) {
        m = grid.size();
        if (m == 0) return -1;
        n = grid[0].size();
        if (n == 0) return -1;
        DFS(grid, 0, 0, grid[0][0]);
        return maxTimes == INT_MIN ? -1 : maxTimes % 1000000007;
    }
};