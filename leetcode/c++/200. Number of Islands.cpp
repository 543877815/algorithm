// floodfill
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
private:
    int d[4][2] = {{0,  1},
                   {1,  0},
                   {0,  -1},
                   {-1, 0}};
    int m, n;
    vector <vector<bool>> visited;

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void DFS(vector <vector<char>> &grid, int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if (inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1')
                DFS(grid, newx, newy);
        }

        return;
    }

public:
    int numIslands(vector <vector<char>> &grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();

        visited = vector < vector < bool >> (m, vector<bool>(n, false));

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    res++;
                    DFS(grid, i, j);
                }
            }
        }
        return res;
    }
};

// 并查集
// 时间复杂度：O(MN∗α(MN))
// 空间复杂度：O(MN)
class Solution {
public:
    vector<int> fa;
    vector<int> rank;

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    void merge(int i, int j) {
        int x = find(i), y = find(j);
        if (rank[x] <= rank[y]) fa[x] = y;
        else fa[y] = x;
        if (rank[x] == rank[y] && x != y) rank[y]++;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;

        // 并查集初始化
        fa.resize(n * m);
        iota(fa.begin(), fa.end(), 0);
        rank = vector<int>(n * m, 1);

        // 构造并查集
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    if (i < n - 1 && grid[i+1][j] == '1') merge(i * m + j, (i + 1) * m + j);
                    if (j < m - 1 && grid[i][j+1] == '1') merge(i * m + j, i * m + j + 1);
                }
            }
        }

        unordered_set<int> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    res.insert(find(i * m + j));
                }
            }
        }

        return res.size();
    }
};