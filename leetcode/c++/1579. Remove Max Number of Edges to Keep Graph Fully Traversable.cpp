// 并查集
// 时间复杂度：O(m a(n)),其中m是数组edges的长度，a是阿克曼函数的反函数
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

    void init(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        rank.resize(n + 1, 1);
    }

    bool check(int n) {
        unordered_set<int> record;
        for (int i = 1; i <= n; i++) {
            record.insert(find(i));
        }
        return record.size() == 1;
    }

    int maxNumEdgesToRemove(int n, vector <vector<int>> &edges) {


        sort(edges.begin(), edges.end(), [&](vector<int> &x, vector<int> &y) {
            if (x[0] != y[0]) return x[0] > y[0]; // 优先执行类型三
            else if (x[1] != y[1]) return x[1] > y[1]; //
            else return x[2] > y[2];
        });

        int res = 0;
        int size = edges.size();

        // 先 type 3, 后 type 2, 表示可以去除的type 2数
        init(n);
        for (int i = 0; i < size; i++) {
            int type = edges[i][0], x = edges[i][1], y = edges[i][2];
            if (type == 3) {
                if (find(x) != find(y)) merge(x, y);
                else res++;
            } else if (type == 2) {
                if (find(x) != find(y)) merge(x, y);
                else res++;
            } else break;
        }
        if (!check(n)) return -1;

        // 先 type 3, 后 type 1, 表示可以去除的type 1数
        init(n);
        for (int i = 0; i < size; i++) {
            int type = edges[i][0], x = edges[i][1], y = edges[i][2];
            if (type == 3) merge(x, y);
            else if (type == 2) continue;
            else if (type == 1) {
                if (find(x) != find(y)) merge(x, y);
                else res++;
            }
        }
        if (!check(n)) return -1;

        return res;
    }
};

// enhancement
class UnionFind {
public:
    vector<int> fa;
    vector<int> rank;
    int n;
    int setCount;

    UnionFind(int _n) :
            n(_n),
            setCount(_n),
            fa(_n),
            rank(_n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    void merge(int i, int j) {
        int x = find(i), y = find(j);
        if (rank[x] <= rank[y]) fa[x] = y;
        else fa[y] = x;
        if (rank[x] == rank[y] && x != y) rank[y]++;
        setCount--;
    }

    bool isConnected(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
public:


    int maxNumEdgesToRemove(int n, vector <vector<int>> &edges) {
        UnionFind ufa(n), ufb(n);
        int res = 0;

        // 编号从0开始
        for (auto &edge : edges) {
            edge[1]--;
            edge[2]--;
        }

        // 公共边
        for (const auto &edge :edges) {
            if (edge[0] == 3) {
                if (ufa.isConnected(edge[1], edge[2])) {
                    res++;
                } else {
                    ufa.merge(edge[1], edge[2]);
                    ufb.merge(edge[1], edge[2]);
                }
            }
        }

        // 独占边
        for (const auto &edge: edges) {
            if (edge[0] == 1) {
                if (ufa.isConnected(edge[1], edge[2])) res++;
                else ufa.merge(edge[1], edge[2]);
            } else if (edge[0] == 2) {
                if (ufb.isConnected(edge[1], edge[2])) res++;
                else ufb.merge(edge[1], edge[2]);
            }
        }

        if (ufa.setCount != 1 || ufb.setCount != 1) return -1;

        return res;
    }
};