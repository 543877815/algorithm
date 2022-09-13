// 深度优先搜索
// 时间复杂度：O(n+m)
// 空间复杂度：O(n)
class Solution {
public:
    vector<bool> color;
    vector<bool> visited;
    int res = true;

    void traverse(vector <vector<int>> graph, int v) {
        if (!res) return;
        visited[v] = true;
        for (int w: graph[v]) {
            if (!visited[w]) {
                color[w] = !color[v];
                traverse(graph, w);
                if (!res) return;
            } else {
                if (color[w] == color[v]) {
                    res = false;
                    return;
                }
            }
        }
    }

    bool isBipartite(vector <vector<int>> &graph) {
        int n = graph.size();
        visited = vector<bool>(n, false);
        color = vector<bool>(n, false);
        for (int v = 0; v < n; v++) {
            if (!visited[v] && res) {
                traverse(graph, v);
            }
        }

        return res;
    }
};

// 广度优先搜索
// 时间复杂度：O(n+m)
// 空间复杂度：O(n)
class Solution {
public:
    vector<bool> color;
    vector<bool> visited;

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visited = vector<bool>(n, false);
        color = vector<bool>(n, false);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    int top = q.front();
                    q.pop();
                    for (int v : graph[top]) {
                        if (!visited[v]) {
                            color[v] = !color[top];
                            q.push(v);
                            visited[v] = true;
                        } else {
                            if (color[v] == color[top]) {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};

// 并查集
// 时间复杂度：O(n+e)
// 空间复杂度：O(n)
class Solution {
private:
    vector<int> fa;
    vector<int> rank;
    inline void init(int n) {
        fa.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            fa[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

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
public:


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        init(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            visited[i] = true;
            for (int v: graph[i]) {
                if (find(i) == find(v)) return false;
                merge(graph[i][0], v);
            }
        }
        return true;
    }
};