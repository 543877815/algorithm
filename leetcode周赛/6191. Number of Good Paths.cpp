// 时间复杂度：O(nlogn+an)
// 空间复杂度：O(n)
class Solution {
    typedef pair<int, int> pii;

    vector<int> root;
    unordered_map<int, int> mp;

    // 找并查集的根
    int findroot(int x) {
        if (root[x] != x) root[x] = findroot(root[x]);
        return root[x];
    }

public:
    int numberOfGoodPaths(vector<int> &vals, vector <vector<int>> &edges) {
        int n = vals.size();

        // 记录树上的边
        vector <vector<int>> e(n);
        for (auto &vec : edges) {
            e[vec[0]].push_back(vec[1]);
            e[vec[1]].push_back(vec[0]);
        }

        // 初始化并查集
        root.resize(n);
        for (int i = 0; i < n; i++) root[i] = i;

        // 将点按点权排序
        vector <pii> vec;
        for (int i = 0; i < n; i++) vec.push_back(pii(vals[i], i));
        sort(vec.begin(), vec.end());

        vector<bool> vis(n);
        long long ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            // 当前枚举的点权有变，清空 mp
            if (vec[i].first != vec[j].first) mp.clear(), j = i;

            // 将 sn 加入树中
            int sn = vec[i].second;
            vis[sn] = true;
            // 一开始没有边和 sn 连接，它所处的连通块只有一个点（也就是它本身）的点权等于 v
            mp[sn] = 1;
            // 枚举从 sn 出发的边
            for (int fn : e[sn])
                if (vis[fn]) {
                    int x = findroot(sn), y = findroot(fn);
                    if (x == y) continue;
                    // 答案就是每个被合并的连通块的 mp 之和
                    ans += mp[y];
                    // 合并两个连通块
                    root[x] = y;
                    mp[y] += mp[x];
                }
        }
        return ans + n;
    }
};
