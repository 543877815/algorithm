// 深度优先搜索（超时了）
class Solution {
public:
    int res = INT_MAX;

    void dfs(vector <vector<int>> &route, vector<bool> &visited, int src, int dst, int k, int price) {
        if (src == dst) {
            res = min(res, price);
            return;
        }
        if (k == -1) return;
        for (int i = 0; i < route.size(); i++) {
            if (!visited[i] && route[src][i] != INT_MAX) {
                visited[i] = true;
                dfs(route, visited, i, dst, k - 1, price + route[src][i]);
                visited[i] = false;
            }
        }
    }

    int findCheapestPrice(int n, vector <vector<int>> &flights, int src, int dst, int k) {
        vector <vector<int>> route(n, vector<int>(n, INT_MAX));
        int m = flights.size();
        for (int i = 0; i < m; i++) {
            int start = flights[i][0];
            int end = flights[i][1];
            int cost = flights[i][2];
            route[start][end] = cost;
        }
        vector<bool> visited = vector<bool>(n, false);
        visited[src] = true;
        dfs(route, visited, src, dst, k, 0);

        return res == INT_MAX ? -1 : res;
    }
};

// 动态规划
// 时间复杂度：O(n^2k)
// 空间复杂度：O(nk)
class Solution {
public:
    int findCheapestPrice(int n, vector <vector<int>> &flights, int src, int dst, int k) {
        const int MAX = INT_MAX / 2;

        // 邻接表
        vector <vector<int>> table = vector < vector < int >> (n, vector<int>(n, MAX));
        int m = flights.size();
        for (int i = 0; i < m; i++) {
            int start = flights[i][0];
            int end = flights[i][1];
            int cost = flights[i][2];
            table[start][end] = cost;
        }

        // dp[t][i] 表示经过中转t次到达城市i的最小花费
        vector <vector<int>> dp = vector < vector < int >> (k + 1, vector<int>(n, MAX));
        for (int j = 0; j < n; j++) {
            dp[0][j] = j == src ? 0 : table[src][j];
        }

        int res = dp[0][dst];
        // 第t次中转
        for (int t = 1; t <= k; t++) {
            // 从i地出发
            for (int i = 0; i < n; i++) {
                // 到达j地
                for (int j = 0; j < n; j++) {
                    dp[t][i] = min(dp[t][i], dp[t - 1][j] + table[j][i]);
                }
            }
            res = min(res, dp[t][dst]);
        }
        return res == MAX ? -1 : res;
    }
};


// 动态规划+状态压缩
// 时间复杂度：O(n^2k)
// 空间复杂度：O(n)
class Solution {
public:
    int findCheapestPrice(int n, vector <vector<int>> &flights, int src, int dst, int k) {
        const int MAX = INT_MAX / 2;

        // 邻接表
        vector <vector<int>> table = vector < vector < int >> (n, vector<int>(n, MAX));
        int m = flights.size();
        for (int i = 0; i < m; i++) {
            int start = flights[i][0];
            int end = flights[i][1];
            int cost = flights[i][2];
            table[start][end] = cost;
        }

        // dp[t][i] 表示经过中转t次到达城市i的最小花费
        vector <vector<int>> dp = vector < vector < int >> (k + 1, vector<int>(n, MAX));
        for (int j = 0; j < n; j++) {
            dp[0][j] = j == src ? 0 : table[src][j];
        }

        int res = dp[0][dst];
        // 第t次中转
        for (int t = 1; t <= k; t++) {
            // 从i地出发
            for (int i = 0; i < n; i++) {
                // 到达j地
                for (int j = 0; j < n; j++) {
                    dp[t][i] = min(dp[t][i], dp[t - 1][j] + table[j][i]);
                }
            }
            res = min(res, dp[t][dst]);
        }
        return res == MAX ? -1 : res;
    }
};


// 动态规划+状态压缩2
// 时间复杂度：O(mk)
// 空间复杂度：O(n)
class Solution {
public:
    int findCheapestPrice(int n, vector <vector<int>> &flights, int src, int dst, int k) {
        const int MAX = INT_MAX / 2;
        int m = flights.size();

        // dp[t][i] 表示经过中转t次到达城市i的最小花费
        vector<int> dp = vector<int>(n, MAX);
        dp[src] = 0;
        int res = dp[dst];
        // 第t次中转
        for (int t = 1; t <= k + 1; t++) {
            vector<int> dpNew = vector<int>(n, MAX);
            // 从i地出发
            for (int i = 0; i < m; i++) {
                int start = flights[i][0];
                int end = flights[i][1];
                int cost = flights[i][2];
                dpNew[end] = min(dpNew[end], dp[start] + cost);
            }
            dp = move(dpNew);
            res = min(res, dp[dst]);
        }

        return res == MAX ? -1 : res;
    }
};