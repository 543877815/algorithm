// 并查集
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> fa;
    vector<int> rank;

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            fa[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    // 秩：以当前结点为根节点的子树的高度(rank)
    void merge(int i, int j) {
        int x = find(i), y = find(j);    //先找到两个根节点
        if (rank[x] <= rank[y])
            fa[x] = y;
        else
            fa[y] = x;
        if (rank[x] == rank[y] && x != y)
            rank[y]++;                   //如果深度相同且根节点不同，则新的根节点的深度+1
    }


    long long countPairs(int n, vector <vector<int>> &edges) {
        int m = edges.size();
        fa = vector<int>(n, 0);
        rank = vector<int>(n, 0);
        init(n);
        for (int i = 0; i < m; i++) {
            merge(edges[i][0], edges[i][1]);
        }

        unordered_map<int, int> mymap;

        for (int i = 0; i < n; i++) {
            int x = find(i);
            mymap[x]++;
        }

        long long res = 0;
        for (auto [key, value]: mymap) {
            res += (long long) value * (n - value);
        }
        return res / 2;
    }
};