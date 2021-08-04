// Dijkstra 算法
// 时间复杂度：O(n^2 + m)
// 空间复杂度：O(n^2)
class Solution {
public:
    int networkDelayTime(vector <vector<int>> &times, int n, int k) {
        int MAX = INT_MAX / 2;
        vector <vector<int>> table = vector < vector < int >> (n, vector<int>(n, MAX));
        for (int i = 0; i < times.size(); i++) {
            int start = times[i][0] - 1;
            int end = times[i][1] - 1;
            int time = times[i][2];
            table[start][end] = time;
        }
        int res = -1;

        vector<int> dis(n, MAX);
        dis[k - 1] = 0;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            int temp = -1;
            for (int j = 0; j < n; j++) {
                // 找到距离最小的点加入点集
                if (!vis[j] && (temp == -1 || dis[j] < dis[temp])) {
                    temp = j;
                }
            }
            vis[temp] = 1;
            for (int j = 0; j < n; j++) {
                dis[j] = min(table[temp][j] + dis[temp], dis[j]);
            }
        }

        for (int i = 0; i < n; i++) res = max(res, dis[i]);
        return res == MAX ? -1 : res;
    }
};