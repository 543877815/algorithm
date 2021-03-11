// 并查集
// 时间复杂度：O(n)
// 空间复杂度：O(26)
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

    bool equationsPossible(vector <string> &equations) {
        int n = equations.size();
        unordered_map<char, int> record;
        int id = 0;
        for (int i = 0; i < n; i++) {
            char a = equations[i][0], b = equations[i][3];
            bool equal = (equations[i][1] == '=') ? true : false;
            if (record.count(a) == 0) record[a] = id++;
            if (record.count(b) == 0) record[b] = id++;
        }

        fa.resize(id);
        iota(fa.begin(), fa.end(), 0);
        rank.resize(id, 1);

        for (int i = 0; i < n; i++) {
            char a = equations[i][0], b = equations[i][3];
            bool equal = (equations[i][1] == '=') ? true : false;
            if (equal) merge(record[a], record[b]);
        }

        for (int i = 0; i < n; i++) {
            char a = equations[i][0], b = equations[i][3];
            bool equal = (equations[i][1] == '=') ? true : false;
            if (!equal && find(record[a]) == find(record[b])) return false;
        }

        return true;
    }
};