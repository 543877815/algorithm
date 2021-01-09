// 并查集
// 时间复杂度：O(Na(N)+M)
// 空间复杂度：O(N)
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

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return - 1;
        fa.resize(n);
        rank = vector<int>(n,1);
        iota(fa.begin(), fa.end(), 0);
        int part = n;
        int m = connections.size();
        for (int i = 0; i < m; i++) {
            int x = connections[i][0], y = connections[i][1];
            if (find(x) != find(y)) {
                part--;
                merge(x, y);
            }
        }
        return part-1;
    }
};