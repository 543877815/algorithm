// 并查集
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> fa;
    vector<int> rank;

    inline void init(int n) {
        fa.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    // 秩：以当前结点为根节点的子树的高度(rank)
    inline void merge(int i, int j) {
        int x = find(i), y = find(j);    //先找到两个根节点
        if (rank[x] <= rank[y])
            fa[x] = y;
        else
            fa[y] = x;
        if (rank[x] == rank[y] && x != y)
            rank[y]++;                   //如果深度相同且根节点不同，则新的根节点的深度+1
    }

    bool validTree(int n, vector <vector<int>> &edges) {
        int m = edges.size();
        init(n);
        for (int i = 0; i < m; i++) {
            int x = edges[i][0], y = edges[i][1];
            if (find(x) != find(y)) {
                merge(x, y);
            } else {
                return false;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (find(i) != find(i + 1)) return false;
        }
        return true;
    }
};