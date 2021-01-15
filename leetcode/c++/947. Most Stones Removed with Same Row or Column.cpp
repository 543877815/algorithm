// 并查集超时了...
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

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int rowId = 0, colId = 0;

        unordered_map<int, int> rows;
        unordered_map<int, int> cols;

        for (int i = 0; i < n; i++) {
            int x = stones[i][0], y = stones[i][1];
            if (rows.count(x) == 0) rows[x] = rowId++;
            if (cols.count(y) == 0) cols[y] = colId++;
        }

        int row_size = rows.size(), col_size = cols.size();
        fa.resize(row_size * col_size);
        iota(fa.begin(), fa.end(), 0);
        rank = vector<int>(row_size * col_size, 1);

        vector<vector<int>> row_same(row_size, vector<int>());
        vector<vector<int>> col_same(col_size, vector<int>());
        for (int i = 0; i < n; i++) {
            int x = stones[i][0], y = stones[i][1];
            int index = rows[x] * col_size + cols[y];
            row_same[rows[x]].emplace_back(index);
            col_same[cols[y]].emplace_back(index);
        }

        for (int i = 0; i < row_same.size(); i++) {
            for (int j = 0; j < row_same[i].size() - 1; j++) {
                merge(row_same[i][j], row_same[i][j+1]);
            }
        }

        for (int i = 0; i < col_same.size(); i++) {
            for (int j = 0; j < col_same[i].size() - 1; j++) {
                merge(col_same[i][j], col_same[i][j+1]);
            }
        }

        unordered_set<int> record;
        for (int i = 0; i < fa.size(); i++) {
            record.insert(find(fa[i]));
        }

        int remain = record.size() - (row_size * col_size - n);
        return n - remain;
    }
};

// 并查集优化
// 时间复杂度：O(na(n))
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> fa;
    vector<int> rank;

    int find(int x) {
        return x == fa[x] ? x : (fa[x]=find(fa[x]));
    }

    void merge(int i, int j) {
        int x = find(i), y = find(j);
        if (rank[x] <= rank[y]) fa[x] = y;
        else fa[y] = x;
        if (rank[x] == rank[y] && x != y) rank[y]++;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int id = 0;
        unordered_map<int, int> hashMap;
        for (int i = 0; i < n; i++) {
            int x = stones[i][0], y = stones[i][1] + 10001;
            if (!hashMap.count(x)) hashMap[x] = id++;
            if (!hashMap.count(y)) hashMap[y] = id++;
        }

        fa.resize(id);
        iota(fa.begin(), fa.end(), 0);
        rank = vector<int>(id, 1);

        for (int i = 0; i < n; i++) {
            int x = stones[i][0], y = stones[i][1] + 10001;
            merge(hashMap[x], hashMap[y]);
        }

        int num = 0;
        for (int i = 0; i < id; i++) {
            if (i == fa[i]) num++;
        }

        return n - num;
    }
};