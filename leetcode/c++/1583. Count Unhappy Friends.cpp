// 模拟
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
public:
    int unhappyFriends(int n, vector <vector<int>> &preferences, vector <vector<int>> &pairs) {
        int m = pairs.size();
        vector <vector<int>> rank = vector < vector < int >> (n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                int no = preferences[i][j];
                rank[i][no] = j;
            }
        }

        vector<bool> visited(n, false);
        int res = 0;
        unordered_map<int, int> hashmap;
        for (int i = 0; i < m; i++) {
            int x = pairs[i][0];
            int y = pairs[i][1];
            for (int j = i + 1; j < m; j++) {
                int u = pairs[j][0];
                int v = pairs[j][1];
                if (rank[x][u] < rank[x][y] && rank[u][x] < rank[u][v]) {
                    if (!visited[x]) {
                        res++;
                        visited[x] = true;
                    }
                    if (!visited[u]) {
                        res++;
                        visited[u] = true;
                    }
                }
                if (rank[x][v] < rank[x][y] && rank[v][x] < rank[v][u]) {
                    if (!visited[x]) {
                        res++;
                        visited[x] = true;
                    }
                    if (!visited[v]) {
                        res++;
                        visited[v] = true;
                    }
                }
                if (rank[y][u] < rank[y][x] && rank[u][y] < rank[u][v]) {
                    if (!visited[y]) {
                        res++;
                        visited[y] = true;
                    }
                    if (!visited[u]) {
                        res++;
                        visited[u] = true;
                    }
                }
                if (rank[y][v] < rank[y][x] && rank[v][y] < rank[v][u]) {
                    if (!visited[y]) {
                        res++;
                        visited[y] = true;
                    }
                    if (!visited[v]) {
                        res++;
                        visited[v] = true;
                    }
                }
            }
        }
        return res;
    }
};