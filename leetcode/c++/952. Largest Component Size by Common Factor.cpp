// reference: https://leetcode-cn.com/problems/largest-component-size-by-common-factor/solution/bing-cha-ji-java-python-by-liweiwei1419/
// 并查集
// 时间复杂度：O(n sqrt(w)),n是A的长度,w=max(A[i])
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
        if (x == y) return;
        fa[x] = y;
        rank[y] += rank[x];
    }

    void init(int n) {
        fa.resize(n);
        rank.resize(n, 1);
        iota(fa.begin(), fa.end(), 0);
    }

    int largestComponentSize(vector<int> &A) {
        int n = A.size();

        // 求上界
        int max_num = INT_MIN;
        for (int i = 0; i < n; i++) {
            max_num = max(max_num, A[i]);
        }

        // 构建并查集
        init(max_num + 1);
        for (int i = 0; i < n; i++) {
            int upBound = sqrt(A[i]);
            for (int j = 2; j <= upBound; j++) {
                if (A[i] % j == 0) {
                    merge(A[i], j);
                    merge(A[i], A[i] / j);
                }
            }
        }

        // 将候选数组映射成代表元，统计代表元出现的次数，找出最大者
        vector<int> cnt(max_num + 1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int root = find(A[i]);
            cnt[root]++;
            res = max(res, cnt[root]);
        }

        return res;
    }
};