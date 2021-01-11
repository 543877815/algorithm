// 并查集
// 时间复杂度：O((M+N)a(N)+NlogN)
// 空间复杂度：O(N)
class Solution {
public:
    vector<int> fa;
    vector<int> rank;

    int find (int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    void merge(int i, int j) {
        int x = find(i), y = find(j);
        if (rank[x] <= rank[y]) fa[x] = y;
        else fa[y] = x;
        if (rank[x] == rank[y] && x != y) rank[y]++;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();

        // 构建并查集
        fa.resize(n);
        rank = vector<int> (n, 1);
        iota(fa.begin(), fa.end(), 0);
        int m = pairs.size();
        for (int i = 0; i < m; i++) {
            int x = pairs[i][0], y = pairs[i][1];
            merge(x, y);
        }

        // 构建索引
        unordered_map<int, vector<char>> hashMap;
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            int x = find(i);
            if (hashMap.count(x) == 0) {
                hashMap[x] = {s[i]};
                index[x] = 0;
            }
            else hashMap[x].push_back(s[i]);
        }

        // 索引内字符排序
        for (auto &t : hashMap) {
            sort(t.second.begin(), t.second.end());
        }

        // 构建新的字符
        for (int i = 0; i < n; i++) {
            int x = find(i);
            s[i] = hashMap[x][index[x]++];
        }

        return s;
    }
};
