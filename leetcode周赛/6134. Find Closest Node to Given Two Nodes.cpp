// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2) {
        int n = edges.size();
        unordered_map<int, int> hashmap;
        for (int i = 0; i < n; i++) {
            hashmap[i] = edges[i];
        }

        vector<int> node1_route(n, INT_MAX);
        node1_route[node1] = 0;
        vector<bool> visited(n, false);

        visited[node1] = true;
        int sum = 0;
        int next = node1;
        while (hashmap.count(next)) {
            next = hashmap[next];
            if (next == -1 || visited[next]) break;
            visited[next] = true;
            sum++;
            node1_route[next] = min(node1_route[next], sum);
        }

        vector<int> node2_route(n, INT_MAX);
        node2_route[node2] = 0;
        visited = vector<bool>(n, false);
        visited[node2]  = true;
        sum = 0;
        next = node2;
        while (hashmap.count(node2)) {
            next = hashmap[next];
            if (next == -1 || visited[next]) break;
            visited[next] = true;
            sum++;
            node2_route[next] = min(node2_route[next], sum);
        }

        int max_route = INT_MAX;
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (node1_route[i] == INT_MAX || node2_route[i] == INT_MAX) continue;
            if (max_route > max(node1_route[i], node2_route[i])) {
                max_route = max(node1_route[i], node2_route[i]);
                res = i;
            }
        }
        return res;
    }
};