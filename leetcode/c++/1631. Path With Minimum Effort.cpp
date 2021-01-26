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

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        if (n == 0) return 0;
        m = heights[0].size();
        if (m == 0) return 0;

        vector<Edge> edges;

        auto dist = [&](int x, int y) -> int {
            return abs(x - y);
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i < n - 1) edges.emplace_back(dist(heights[i+1][j], heights[i][j]), getIndex(i+1, j), getIndex(i, j));
                if (j < m - 1) edges.emplace_back(dist(heights[i][j+1], heights[i][j]), getIndex(i, j+1), getIndex(i, j));
            }
        }

        int size = m * n;
        fa.resize(size);
        iota(fa.begin(), fa.end(), 0);
        rank.resize(size, 1);

        sort(edges.begin(), edges.end(), [](Edge a, Edge b) -> int {return a.len < b.len;});
        int res = 0;
        for (auto & [len, x, y] : edges) {
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
