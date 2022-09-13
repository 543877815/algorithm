// kruskal ���鼯
// ʱ�临�Ӷȣ�O(eloge + ne)
// �ռ临�Ӷȣ�O(n)
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

    // �ȣ��Ե�ǰ���Ϊ���ڵ�������ĸ߶�(rank)
    inline void merge(int i, int j) {
        int x = find(i), y = find(j);    //���ҵ��������ڵ�
        if (rank[x] <= rank[y])
            fa[x] = y;
        else
            fa[y] = x;
        if (rank[x] == rank[y] && x != y)
            rank[y]++;                   //��������ͬ�Ҹ��ڵ㲻ͬ�����µĸ��ڵ�����+1
    }

    int minimumCost(int n, vector <vector<int>> &connections) {
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

// Prim �㷨
// ʱ�临�Ӷȣ�O(n + eloge)
// �ռ临�Ӷȣ�O(n + e)
class Solution {
public:
    int minimumCost(int n, vector <vector<int>> &connections) {
        int m = connections.size();
        auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b) {  // [����, Ŀ��]
            return a.first > b.first;
        };
        priority_queue < pair < int, int >, vector < pair < int, int >>, decltype(cmp) > pq(cmp);
        vector < vector < pair < int, int>>> edges(n + 1);
        for (int i = 0; i < m; i++) {
            int start = connections[i][0], end = connections[i][1], weight = connections[i][2];
            edges[start].emplace_back(end, weight);
            edges[end].emplace_back(start, weight);
        }

        set<int> s;
        int res = 0;
        pq.push(make_pair(0, 1));
        while (!pq.empty() && s.size() != n) {
            auto [weight, node] = pq.top();
            pq.pop();
            if (s.find(node) == s.end()) {
                s.insert(node);
                res += weight;
                for (auto [next_node, weight]: edges[node]) {
                    pq.push(make_pair(weight, next_node));
                }
            }
        }

        return s.size() == n ? res : -1;
    }
};