// 并查集
// 时间复杂度：O(n^2m+nlogn)
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
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        rank.resize(n, 1);
    }

    bool check(const string &a, const string &b, int m) {
        int num = 0;
        for (int i = 0; i < m; i++) {
            if (a[i] != b[i]) num++;
            if (num > 2) return false;
        }
        return true;
    }

    int numSimilarGroups(vector <string> &strs) {
        int n = strs.size();
        int m = strs[0].size();
        init(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = find(i), y = find(j);
                if (x == y) continue;
                if (check(strs[i], strs[j], m)) merge(i, j);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) res++;
        }
        return res;
    }


};