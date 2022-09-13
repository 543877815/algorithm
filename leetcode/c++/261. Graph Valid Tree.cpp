// ���鼯
// ʱ�临�Ӷȣ�O(nlogn)
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