// ���鼯
// ʱ�临�Ӷȣ�O(n^2logn)
// �ռ临�ӵģ�O(n)
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