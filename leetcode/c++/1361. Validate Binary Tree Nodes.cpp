// 并查集
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> fa;
    vector<int> rank;

    int find(int x) {
        return (x == fa[x]) ? x : (fa[x] = find(fa[x]));
    }

    void merge(int i, int j) {
        int x = find(i), y = find(j);
        if (rank[x] <= rank[y]) fa[x] = y;
        else fa[y] = x;
        if (rank[x] == rank[y] && x != y) rank[y]++;
    }

    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild) {
        vector<int> inDegree(n, 0);
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                inDegree[leftChild[i]]++;
                merge(i, leftChild[i]);
            }
            if (rightChild[i] != -1) {
                inDegree[rightChild[i]]++;
                merge(i, rightChild[i]);
            }
        }
        int count_one = 0;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 1) count_one++;
        }
        if (count_one != n - 1) return false;
        int init_fa = fa[0];
        for (int i = 1; i < n; i++) {
            if (init_fa != find(fa[i])) return false;
        }
        return true;
    }
};