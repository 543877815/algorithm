// 并查集
// 时间复杂度：O(n^2logn)
// 空间复杂的：O(n)
class Solution {
public:

    vector<int> fa;
    vector<int> rank;

    inline void init(int n) {
        fa = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; ++i) {
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

    int findCircleNum(vector <vector<int>> &isConnected) {
        int n = isConnected.size();
        init(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j]) {
                    merge(i, j);
                }
            }
        }

        unordered_set<int> myset;
        for (int i = 0; i < n; i++) {
            myset.insert(find(i));
        }

        return myset.size();
    }
};