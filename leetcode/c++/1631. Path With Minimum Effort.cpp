// 并查集
// 提交未通过，超时
class Solution {
public:
    int dp[4][2] = {
            {1,  0},
            {0,  1},
            {-1, 0},
            {0,  -1}
    };

    int n, m;
    vector<int> fa;
    vector<int> rank;
    vector <vector<bool>> visited;

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

    void dfs(vector <vector<int>> &heights, int x, int y, int dis) {
        visited[x][y] = true;
        if (find(fa[getIndex(0, 0)]) == find(fa[getIndex(n - 1, m - 1)])) return;
        for (int i = 0; i < 4; i++) {
            int newX = x + dp[i][0], newY = y + dp[i][1];
            if (isArea(newX, newY) && !visited[newX][newY] && abs(heights[newX][newY] - heights[x][y]) <= dis) {
                merge(getIndex(x, y), getIndex(newX, newY));
                dfs(heights, newX, newY, dis);
            }
        }
    }

    int minimumEffortPath(vector <vector<int>> &heights) {
        n = heights.size();
        if (n == 0) return 0;
        m = heights[0].size();
        if (m == 0) return 0;
        int size = n * m;
        fa.resize(size);
        iota(fa.begin(), fa.end(), 0);
        rank = vector<int>(size, 1);


        for (int i = 0; i < 1000000; i++) {
            visited = vector < vector < bool >> (n, vector<bool>(m, false));
            dfs(heights, 0, 0, i);
            if (find(fa[getIndex(0, 0)]) == find(fa[getIndex(n - 1, m - 1)])) return i;
        }

        return 0;
    }
};

// 并查集
// 时间复杂度：O(n^2logn)
// 空间复杂度：O(n^2)
class Solution {
public:
    vector<int> fa;
    vector<int> rank;
    int n, m;

    struct Edge {
        int len, x, y;

        Edge(int len, int x, int y) : len(len), x(x), y(y) {}
    };

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    void merge(int i, int j) {
        int x = find(i), y = find(j);
        if (rank[x] <= rank[y]) fa[x] = y;
        else fa[y] = x;
        if (rank[x] == rank[y] && x != y) rank[y]++;
    }

    int getIndex(int x, int y) {
        return x * m + y;
    }

    int minimumEffortPath(vector <vector<int>> &heights) {
        n = heights.size();
        if (n == 0) return 0;
        m = heights[0].size();
        if (m == 0) return 0;

        vector <Edge> edges;

        auto dist = [&](int x, int y) -> int {
            return abs(x - y);
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i < n - 1)
                    edges.emplace_back(dist(heights[i + 1][j], heights[i][j]), getIndex(i + 1, j), getIndex(i, j));
                if (j < m - 1)
                    edges.emplace_back(dist(heights[i][j + 1], heights[i][j]), getIndex(i, j + 1), getIndex(i, j));
            }
        }

        int size = m * n;
        fa.resize(size);
        iota(fa.begin(), fa.end(), 0);
        rank.resize(size, 1);

        sort(edges.begin(), edges.end(), [](Edge a, Edge b) -> int { return a.len < b.len; });
        int res = 0;
        for (auto &[len, x, y] : edges) {
            if (find(0) != find(size - 1)) {
                merge(x, y);
                res = len;
            } else {
                return res;
            }
        }

        return res;

    }
};