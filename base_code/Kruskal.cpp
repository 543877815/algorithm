// kruskal 并查集
// 时间复杂度：O(eloge + ne)
// 空间复杂度：O(n)
// 例子见 1135. 最低成本联通所有城市 https://leetcode.cn/problems/connecting-cities-with-minimum-cost/

#include <bits/stdc++.h>

using namespace std;

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

    int minimumCost(int n, vector<vector<int>> &connections) {
        init(n);
        sort(connections.begin(), connections.end(), [&](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });

        int m = connections.size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            int x = connections[i][0], y = connections[i][1], weight = connections[i][2];
            if (find(x) != find(y)) {
                merge(x, y);
                res += weight;
            }
        }

        for (int i = 1; i <= n - 1; i++) {
            if (find(i) != find(i + 1)) return -1;
        }

        return res;
    }
};

int main() {
//    int n = 3;
//    vector<vector<int>> connections = {{1, 2, 5},
//                                      {1, 3, 6},
//                                      {2, 3, 1}};

    int n = 4;
    vector<vector<int>> connections = {{1, 2, 3},
                                       {3, 4, 4}};
    auto a = new Solution();
    cout << a->minimumCost(n, connections);
}