// 并查集
// 时间复杂度：O(n)
// 空间复杂度：O(n)
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

    vector<int> findRedundantConnection(vector <vector<int>> &edges) {
        int n = edges.size();
        fa = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
            rank[i] = 1;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int x = edges[i][0] - 1, y = edges[i][1] - 1;
            if (find(x) == find(y)) return edges[i];
            merge(x, y);
        }

        return res;
    }
};