// DFS
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
private:
    vector<bool> visited;
    vector <vector<int>> edge;

public:
    bool findWhetherExistsPath(int n, vector <vector<int>> &graph, int start, int target) {
        visited = vector<bool>(n, false);
        visited[start] = true;
        edge = vector < vector < int >> (n);
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i][0] == start && graph[i][1] == target) return true;
            edge[graph[i][0]].push_back(graph[i][1]);
        }
        return DFS(start, target);
    }

    bool DFS(int start, int target) {
        if (target == start) return true;
        for (int i = 0; i < edge[start].size(); i++) {
            if (!visited[edge[start][i]]) {
                visited[edge[start][i]] = true;
                if (DFS(edge[start][i], target)) return true;
                visited[edge[start][i]] = false;
            }
        }
        return false;
    }
};