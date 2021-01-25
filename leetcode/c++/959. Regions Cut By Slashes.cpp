// 并查集
// 时间复杂度：O(n^2logn)
// 空间复杂度：O(n^2)
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

    int regionsBySlashes(vector <string> &grid) {
        int n = grid.size();
        if (n == 0) return 1;
        fa.resize(4 * n * n);
        iota(fa.begin(), fa.end(), 0);
        rank.resize(4 * n * n, 1);

        // 遍历方块
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int idx = i * n + j; // 方块的编号
                // 第 idx 方块中 的 k 号小三角形
                // 三角形编号如下：
                //      0
                //   3     1
                //      2
                if (i < n - 1) {
                    // 第 idx 个方块中最下面的三角形 和 第 idx + n 个方块中最上面的三角形
                    merge(idx * 4 + 2, (idx + n) * 4);
                }
                if (j < n - 1) {
                    // 第 idx 个方块中最右边的三角形 和 第 idx 个方块最左边的三角形
                    merge(idx * 4 + 1, (idx + 1) * 4 + 3);
                }
                if (grid[i][j] == '/') {
                    merge(idx * 4 + 0, idx * 4 + 3);
                    merge(idx * 4 + 1, idx * 4 + 2);
                } else if (grid[i][j] == '\\') {
                    merge(idx * 4 + 0, idx * 4 + 1);
                    merge(idx * 4 + 2, idx * 4 + 3);
                } else {
                    merge(idx * 4 + 0, idx * 4 + 1);
                    merge(idx * 4 + 1, idx * 4 + 2);
                    merge(idx * 4 + 2, idx * 4 + 3);
                }
            }
        }
        unordered_set<int> record;
        for (int i = 0; i < 4 * n * n; i++) {
            record.insert(find(i));
        }
        return record.size();
    }
};