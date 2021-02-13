// 贪心算法
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        int n = row.size();
        int res = 0;
        for (int i = 0; i < n; i += 2) {
            int x = row[i];
            if (row[i + 1] == (x ^ 1)) continue;
            res++;
            for (int j = i + 1; j < n; j++) {
                if (row[j] == (x ^ 1)) {
                    int tmp = row[j];
                    row[j] = row[i + 1];
                    row[i + 1] = tmp;
                    break;
                }
            }
        }
        return res;
    }
};


// 并查集
// 时间复杂度：O(nlogn)
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

    int minSwapsCouples(vector<int> &row) {
        int n = row.size();
        int group = n / 2;
        fa.resize(group);
        iota(fa.begin(), fa.end(), 0);
        rank.resize(group, 1);
        for (int i = 0; i < n; i += 2) {
            int x = row[i] / 2, y = row[i + 1] / 2;
            merge(x, y);
        }

        unordered_map<int, int> count;
        for (int i = 0; i < group; i++) {
            int x = find(fa[i]);
            count[x]++;
        }

        int res = 0;
        for (const auto&[key, value]: count) {
            res += value - 1;
        }

        return res;
    }
};