// 时间复杂度：O(n)
// 空间复杂度：O(n)

class Solution {
private:
    // 定义 dp[u] 表示以 u 为根的子树，它的所有子节点到它的距离之和
    // 定义 sz[u] 表示以 u 为根的子树的节点数量
    // dp[u] = \sum_{v\in son[u]} dp[v] + sz[v]
    vector<int> ans, sz, dp;
    vector <vector<int>> graph;

    // u: from, f: to
    void dfs(int u, int f) {
        sz[u] = 1;
        dp[u] = 0;
        for (auto &v: graph[u]) {
            if (v == f) continue;  // from == to
            dfs(v, u);
            dp[u] += dp[v] + sz[v];
            sz[u] += sz[v];
        }
    }

    // 让 v 换到根的位置，u 变为其孩子节点，同时维护原有的 dp 信息。
    // u: from, f: to
    void dfs2(int u, int f) {
        ans[u] = dp[u];
        for (auto &v: graph[u]) {
            if (v == f) continue;
            // 回溯开始记录状态
            int pu = dp[u], pv = dp[v];
            int su = sz[u], sv = sz[v];

            // from 修改为儿子
            dp[u] -= dp[v] + sz[v];
            sz[u] -= sz[v];

            // to 修改为父亲
            dp[v] += dp[u] + sz[u];
            sz[v] += sz[u];

            // 深度优先遍历
            dfs2(v, u);

            // 回溯结束状态调整
            dp[u] = pu, dp[v] = pv;
            sz[u] = su, sz[v] = sv;
        }
    }

public:
    vector<int> sumOfDistancesInTree(int N, vector <vector<int>> &edges) {
        ans.resize(N, 0);
        sz.resize(N, 0);
        dp.resize(N, 0);
        graph.resize(N, {});
        for (auto &edge: edges) {
            // u: from, v: to
            int u = edge[0], v = edge[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
};

int main() {
    auto *solution = new Solution();
    vector <vector<int>> graph = {{0, 1},
                                  {0, 2},
                                  {2, 3},
                                  {2, 4},
                                  {2, 5}};
    solution->sumOfDistancesInTree(6, graph);

}