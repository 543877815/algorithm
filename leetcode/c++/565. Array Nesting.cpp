// 并查集
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    // 秩：以当前结点为根节点的子树的高度(rank)
    inline void merge(int i, int j) {
        int x = find(i), y = find(j);    //先找到两个根节点
        if (rank[x] <= rank[y])
            fa[x] = y;
        else
            fa[y] = x;
        if (rank[x] == rank[y] && x != y)
            rank[y]++;                   //如果深度相同且根节点不同，则新的根节点的深度+1
    }

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    vector<int> fa;
    vector<int> rank;

    int arrayNesting(vector<int> &nums) {
        int n = nums.size();
        fa = vector<int>(n, 0);
        for (int i = 0; i < n; i++) fa[i] = i;
        rank = vector<int>(n, 1);
        for (int i = 0; i < n; i++) {
            merge(nums[i], i);
        }

        unordered_map<int, int> hashmap;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int j = find(nums[i]);
            hashmap[j]++;
            res = max(res, hashmap[j]);
        }

        return res;
    }
};

// 图
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int arrayNesting(vector<int> &nums) {
        int ans = 0, n = nums.size();
        vector<int> vis(n);
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            while (!vis[i]) {
                vis[i] = true;
                i = nums[i];
                ++cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

