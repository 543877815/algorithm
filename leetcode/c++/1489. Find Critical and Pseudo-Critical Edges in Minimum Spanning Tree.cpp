// 并查集+Kruskal算法，n和m分别是图中的节点数和边数
// 时间复杂度：O(m^2*a(n)) a 是阿克曼函数的反函数
// 空间复杂度：O(m+n)
class Solution {
public:
    vector<int> fa;
    vector<int> rank;
    int fa_count;
    int find(int x) {
        return x == fa[x] ? x : (fa[x]=find(fa[x]));
    }

    // 按高度合并
    void merge(int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return;
        fa[x] = y;
        rank[y] += rank[x];
        fa_count--;
    }

    // 返回权重
    int getWeight(int n, vector<vector<int>> &edges, int index, bool include) {
        // 初始化并查集
        fa.resize(n);
        fa_count = n;
        iota(fa.begin(), fa.end(), 0);
        rank.resize(n, 0);
        int num = 0, res = 0;
        if (include) {
            int x = edges[index][0], y = edges[index][1], weight = edges[index][2];
            merge(x, y);
            res += weight;
            num++;
        }
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0], y = edges[i][1], weight = edges[i][2];
            if (find(x) != find(y) && i != index) {
                merge(x, y);
                num++;
                res += weight;
                if (num == n - 1) break;
            }
        };
        return res;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> criticalEdges;
        vector<int> pseudoCriticalEdges;
        int edgeSize = edges.size();

        // 加索引
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        // 按照权重排序
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) -> int {return a[2] < b[2] ;});

        // 得到最小图的权重
        int initWeight = getWeight(n, edges, -1, false);

        // 删除一条边
        for (int i = 0; i < edges.size(); i++) {
            int index = edges[i][3];

            // 判断是否是关键边
            int newWeight = getWeight(n, edges, i, false);
            if (fa_count > 1 || (fa_count == 1 && newWeight > initWeight)) {
                criticalEdges.push_back(index);
                continue;
            }

            // 判断是否为伪关键边
            newWeight = getWeight(n, edges, i, true);
            if (newWeight == initWeight) pseudoCriticalEdges.push_back(index);
        }

        vector<vector<int>> res = {criticalEdges, pseudoCriticalEdges};
        return res;
    }
};



// https://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/solution/zhao-dao-zui-xiao-sheng-cheng-shu-li-de-gu57q/
// 并查集+Tarjan算法
// 时间复杂度：O(mlogm)
// 空间复杂度：O(m+n)

// 并查集模板
class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    // 当前连通分量数目
    int setCount;

public:
    UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }

    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }

    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

// Tarjan 算法求桥边模版
class TarjanSCC {
private:
    const vector<vector<int>>& edges;
    const vector<vector<int>>& edgesId;
    vector<int> low;
    vector<int> dfn;
    vector<int> ans;
    int n;
    int ts;

private:
    void getCuttingEdge_(int u, int parentEdgeId) {
        low[u] = dfn[u] = ++ts;
        for (int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i];
            int id = edgesId[u][i];
            if (dfn[v] == -1) {
                getCuttingEdge_(v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    ans.push_back(id);
                }
            }
            else if (id != parentEdgeId) {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

public:
    TarjanSCC(int n_, const vector<vector<int>>& edges_, const vector<vector<int>>& edgesId_): \
        edges(edges_), edgesId(edgesId_), low(n_, -1), dfn(n_, -1), n(n_), ts(-1) {}

    vector<int> getCuttingEdge() {
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                getCuttingEdge_(i, -1);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const auto& u, const auto& v) {
            return u[2] < v[2];
        });

        UnionFind uf(n);
        vector<vector<int>> ans(2);
        vector<int> label(m);
        for (int i = 0; i < m;) {
            // 找出所有权值为 w 的边，下标范围为 [i, j)
            int w = edges[i][2];
            int j = i;
            while (j < m && edges[j][2] == edges[i][2]) {
                ++j;
            }

            // 存储每个连通分量在图 G 中的编号
            unordered_map<int, int> compToId;
            // 图 G 的节点数
            int gn = 0;

            for (int k = i; k < j; ++k) {
                int x = uf.findset(edges[k][0]);
                int y = uf.findset(edges[k][1]);
                if (x != y) {
                    if (!compToId.count(x)) {
                        compToId[x] = gn++;
                    }
                    if (!compToId.count(y)) {
                        compToId[y] = gn++;
                    }
                }
                else {
                    // 将自环边标记为 -1
                    label[edges[k][3]] = -1;
                }
            }

            // 图 G 的边
            vector<vector<int>> gm(gn), gmid(gn);

            for (int k = i; k < j; ++k) {
                int x = uf.findset(edges[k][0]);
                int y = uf.findset(edges[k][1]);
                if (x != y) {
                    int idx = compToId[x], idy = compToId[y];
                    gm[idx].push_back(idy);
                    gmid[idx].push_back(edges[k][3]);
                    gm[idy].push_back(idx);
                    gmid[idy].push_back(edges[k][3]);
                }
            }

            vector<int> bridges = TarjanSCC(gn, gm, gmid).getCuttingEdge();
            // 将桥边（关键边）标记为 1
            for (int id: bridges) {
                ans[0].push_back(id);
                label[id] = 1;
            }

            for (int k = i; k < j; ++k) {
                uf.unite(edges[k][0], edges[k][1]);
            }

            i = j;
        }

        // 未标记的边即为非桥边（伪关键边）
        for (int i = 0; i < m; ++i) {
            if (!label[i]) {
                ans[1].push_back(i);
            }
        }

        return ans;
    }
};
