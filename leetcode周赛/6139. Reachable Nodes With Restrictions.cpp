// bfs
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int reachableNodes(int n, vector <vector<int>> &edges, vector<int> &restricted) {
        unordered_map<int, vector<int>> hashmap;
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            int start = edges[i][0], end = edges[i][1];
            hashmap[start].push_back(end);
            hashmap[end].push_back(start);
        }

        vector<bool> visited(n, false);
        for (int i = 0; i < restricted.size(); i++) {
            visited[restricted[i]] = true;
        }

        visited[0] = true;
        queue<int> q;
        q.push(0);
        int res = 0;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            res++;
            for (auto edge: hashmap[top]) {
                if (!visited[edge]) {
                    visited[edge] = true;
                    q.push(edge);
                }
            }
        }

        return res;
    }
};