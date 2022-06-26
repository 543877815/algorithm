// ���鼯
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
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

    // �ȣ��Ե�ǰ���Ϊ���ڵ�������ĸ߶�(rank)
    void merge(int i, int j) {
        int x = find(i), y = find(j);    //���ҵ��������ڵ�
        if (rank[x] <= rank[y])
            fa[x] = y;
        else
            fa[y] = x;
        if (rank[x] == rank[y] && x != y)
            rank[y]++;                   //��������ͬ�Ҹ��ڵ㲻ͬ�����µĸ��ڵ�����+1
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