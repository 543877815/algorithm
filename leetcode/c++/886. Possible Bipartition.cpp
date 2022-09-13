// 二分图+深度优先搜索
// 时间复杂度：O(n+e)
// 空间复杂度：O(n)
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int m = dislikes.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++) {
            int a = dislikes[i][0] - 1, b = dislikes[i][1] - 1;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool>visited(n, false);
        vector<bool>color(n, false);
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