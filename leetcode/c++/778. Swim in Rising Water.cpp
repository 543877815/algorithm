// 并查集 二分查找
// 时间复杂度：O(n^2logn)
// 空间复杂度：O(n^2)
class Solution {
public:
    vector<int> fa;
    vector<int> rank;
    int n, m;

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    void merge(int i, int j) {
        int x = find(i), y = find(j);
        if (rank[x] <= rank[y]) fa[x] = y;
        else fa[y] = x;
        if (rank[x] == rank[y] && x != y) rank[y]++;
    }

    void init(int size) {
        fa.resize(size);
        iota(fa.begin(), fa.end(), 0);
        rank.resize(size, 1);
    }

    bool isConnected(int i, int j) {
        return find(i) == find(j);
    }

    int getIndex(int i, int j) {
        return i * m + j;
    }

    int swimInWater(vector <vector<int>> &grid) {
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        if (m == 0) return 0;
        int size = n * m;

        int left = max(grid[0][0], grid[n - 1][m - 1]), right = size - 1;
        int middle;
        while (left <= right) {
            init(size);
            middle = (left + right) / 2;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i < n - 1) {
                        if (grid[i][j] <= middle && grid[i + 1][j] <= middle) {
                            merge(getIndex(i, j), getIndex(i + 1, j));
                        }
                    }
                    if (j < m - 1) {
                        if (grid[i][j] <= middle && grid[i][j + 1] <= middle) {
                            merge(getIndex(i, j), getIndex(i, j + 1));
                        }
                    }
                }
            }

            if (isConnected(0, size - 1)) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return isConnected(0, size - 1) ? middle : middle +
                                                   1;  // case : [[7,23,21,9,5],[3,20,8,18,15],[14,13,1,0,22],[2,10,24,17,12],[6,16,19,4,11]]
    }
};