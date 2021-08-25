// 深度优先搜索
// 时间复杂度：O(nx2^n)
// 空间复杂度：O(n)
class Solution {
public:
    vector <vector<int>> res;

    void dfs(vector <vector<int>> &graph, vector<bool> &visited, vector<int> &route, int prev) {
        int n = graph.size();
        if (prev == n - 1) {
            res.push_back(route);
            return;
        }
        for (int i = 0; i < graph[prev].size(); i++) {
            int next = graph[prev][i];
            if (!visited[next]) {
                visited[next] = true;
                route.push_back(next);
                dfs(graph, visited, route, next);
                route.pop_back();
                visited[next] = false;
            }
        }
    }

    vector <vector<int>> allPathsSourceTarget(vector <vector<int>> &graph) {
        int n = graph.size();
        const int MAX = INT_MAX / 2;
        vector<bool> visited = vector<bool>(n, false);
        visited[0] = true;
        int prev = 0;
        vector<int> route = {prev};
        dfs(graph, visited, route, prev);
        return res;
    }
};

// 纯净版
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& graph, vector<int> &route, int prev) {
        int n = graph.size();
        if (prev == n - 1) {
            res.push_back(route);
            return;
        }
        for (int i = 0; i < graph[prev].size(); i++) {
            int next = graph[prev][i];
            route.push_back(next);
            dfs(graph, route, next);
            route.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        const int MAX = INT_MAX / 2;
        int prev = 0;
        vector<int> route = {prev};
        dfs(graph, route, prev);
        return res;
    }
};
