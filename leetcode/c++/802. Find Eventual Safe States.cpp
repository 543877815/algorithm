// 深度优先搜索+回溯：超时
class Solution {
public:
    vector<bool> unsafe;

    void dfs(vector <vector<int>> &graph, vector<bool> &vis, int from) {
        int n = graph[from].size();
        for (int i = 0; i < n; i++) {
            int to = graph[from][i];
            if (vis[to]) unsafe[from] = true;
            else {
                vis[to] = true;
                dfs(graph, vis, to);
                if (unsafe[to]) unsafe[from] = true;
                else vis[to] = false;
            }
        }
    }

    vector<int> eventualSafeNodes(vector <vector<int>> &graph) {
        // 初始化
        int n = graph.size();
        unsafe = vector<bool>(n, false);
        vector<bool> vis = vector<bool>(n, false);
        for (int i = 0; i < n; i++) {
            vis[i] = true;
            dfs(graph, vis, i);
            if (!unsafe[i]) vis[i] = false;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!unsafe[i]) res.push_back(i);
        }
        return res;
    }
};

// 深度优先搜索 + 三色标记法
// 时间复杂度：O(n+m)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> eventualSafeNodes(vector <vector<int>> &graph) {
        int n = graph.size();
        vector<int> color(n);

        function<bool(int)> safe = [&](int x) {
            if (color[x] > 0) {
                return color[x] == 2;
            }
            color[x] = 1;
            for (int y : graph[x]) {
                if (!safe(y)) {
                    return false;
                }
            }
            color[x] = 2;
            return true;
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (safe(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }

};


// 拓扑排序
// 根据题意，若一个节点没有出边，则该节点是安全的；
// 若一个节点出边相连的点都是安全的，则该节点也是安全的。
// 根据这一性质，我们可以将图中所有边反向，得到一个反图，然后在反图上运行拓扑排序。
// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    vector<int> eventualSafeNodes(vector <vector<int>> &graph) {
        int n = graph.size();
        vector <vector<int>> rg(n);
        vector<int> inDeg(n);
        for (int x = 0; x < n; ++x) {
            for (int y : graph[x]) {
                rg[y].push_back(x);
            }
            inDeg[x] = graph[x].size();
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int y = q.front();
            q.pop();
            for (int x : rg[y]) {
                if (--inDeg[x] == 0) {
                    q.push(x);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
