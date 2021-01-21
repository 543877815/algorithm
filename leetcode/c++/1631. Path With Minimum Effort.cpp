class Solution {
public:
    int dp[4][2] = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1}
    };

    int n, m;
    vector<int> fa;
    vector<int> rank;
    bool isArea(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    int getIndex(int x, int y) {
        return x * m + y;
    }

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    void merge(int i, int j) {
        int x = find(i), y = find(j);
        if (rank[x] <= rank[y]) fa[x] = y;
        else fa[y] = x;
        if (rank[x] == rank[y]) rank[y]++;
    }

    void dfs(vector<vector<int>> &heights, int x, int y, int dis) {
        if (find(fa[getIndex(0,0)]) == find(fa[getIndex(n-1, m-1)])) return;
        for (int i = 0; i < 4; i++) {
            int newX = x + dp[i][0], newY = y + dp[i][1];
            if (isArea(newX, newY) && !visited[newX][newY] && abs(heights[newX][newY] - heights[x][y]) <= dis) {
                merge(getIndex(x, y), getIndex(newX, newY));
                dfs(heights, newX, newY, dis);
            }
        }
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        if (n == 0) return 0;
        m = heights[0].size();
        if (m == 0) return 0;
        int size = n * m;
        fa.resize(size);
        iota(fa.begin(), fa.end(), 0);
        rank = vector<int>(size, 1);


        for (int i = 0; i < 1000000; i++) {
            dfs(heights, 0, 0, i);
            if (find(fa[getIndex(0,0)]) == find(fa[getIndex(n-1, m-1)])) return i;
        }

        return 0;
    }
};