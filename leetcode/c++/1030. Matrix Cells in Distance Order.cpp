// 广度优先遍历
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
private:
    int m, n;
    int dp[4][2] = {
            {-1,0},
            {0,-1},
            {0,1},
            {1,0}
    };
    queue<pair<int, int>> q;
    bool isArea(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        vector<vector<bool>> visited = vector<vector<bool>>(R, vector<bool>(C, false));
        res.push_back({r0, c0});
        visited[r0][c0] = true;
        m = R;
        n = C;
        q.push({r0, c0});
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x + dp[i][0];
                int newy = y + dp[i][1];
                if (isArea(newx, newy) && !visited[newx][newy]) {
                    q.push({newx, newy});
                    visited[newx][newy] = true;
                    res.push_back({newx, newy});
                }
            }
        }
        return res;
    }
};