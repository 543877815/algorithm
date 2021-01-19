// 并查集
// 时间复杂度：O(n*hw*log(hw))  n为消除砖块的次数
// 空间复杂度：O(hw)
class Solution {
public:
    const int dp[4][2] = {
            {0,1},
            {0,-1},
            {-1,0},
            {1,0}
    };
    int rows, cols;
    vector<int> fa;
    vector<int> rank;

    int find(int x) {
        if (fa[x] == x) {
            return x;
        }
        int newf = find(fa[x]);
        fa[x] = newf;
        return fa[x];
    }

    void merge(int i, int j) {
        int x = find(i), y = find(j);
        if (x == y)  return;
        fa[x] = y;
        rank[y] += rank[x];
    }

    int getSize(int x) {
        return rank[find(x)];
    }


    int getIndex(int x, int y) {
        return x * cols + y;
    }

    int isArea(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<vector<int>> status = grid;
        rows = grid.size();
        cols = grid[0].size();

        int size =  rows * cols; // 编号 n * m 表示屋顶
        fa.resize(size + 1); // 加 1 表示屋顶
        iota(fa.begin(), fa.end(), 0);
        rank = vector<int>(size + 1, 1);

        // 将连接点变成 0
        for (int i = 0; i < hits.size(); i++) {
            status[hits[i][0]][hits[i][1]] = 0;
        }

        // 构造并查集
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (status[i][j] == 1) {
                    if (i == 0) merge(getIndex(i, j), size); // 与屋顶相连
                    if (i > 0 && status[i-1][j] == 1) merge(getIndex(i-1, j), getIndex(i, j));
                    if (j > 0 && status[i][j-1] == 1) merge(getIndex(i, j-1), getIndex(i, j));
                }
            }
        }

        vector<int>res(hits.size(), 0);
        for (int i = hits.size() - 1; i >= 0; i--) {
            int x = hits[i][0], y = hits[i][1];
            if (grid[x][y] == 0) continue;
            int origin = getSize(size);
            // 补回砖块
            if (x == 0) merge(y, size);

            for (int i = 0; i < 4; i++) {
                int newX = x + dp[i][0], newY = y + dp[i][1];
                if (isArea(newX, newY) && status[newX][newY] == 1) {
                    merge(getIndex(x, y), getIndex(newX, newY));
                }
            }
            int current = getSize(size);
            res[i] = max(0, current - origin - 1);
            status[x][y] = 1;
        }

        return res;
    }
};