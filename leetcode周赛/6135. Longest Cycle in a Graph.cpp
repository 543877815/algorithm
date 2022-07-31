// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int longestCycle(vector<int> &edges) {
        int n = edges.size();
        vector<int> inDegree(n, 0);
        vector<int> outDegree(n, 0);
        unordered_map<int, int> hashmap;
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                inDegree[edges[i]]++;
                outDegree[i]++;
                hashmap[i] = edges[i];
            }
        }
        int res = -1;
        vector<int> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (inDegree[i] && outDegree[i] && !visited[i]) {
                int next = i;
                queue<int> q;
                while (hashmap.count(next)) {
                    visited[next] = true;
                    q.push(next);
                    next = hashmap[next];
                    if (visited[next]) {
                        while (!q.empty() && q.front() != next) {
                            q.pop();
                        }
                        res = max(res, (int) q.size());
                        break;
                    }
                }
            }
        }
        return res == 0 ? -1 : res;
    }
};