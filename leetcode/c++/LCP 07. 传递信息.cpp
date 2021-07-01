// 深度优先搜索
// 时间复杂度：O(n^k)
// 空间复杂度：O(n+m+n^k)
class Solution {
public:
    void dfs(vector <vector<bool>> &graph, int k, int curr, int &res) {
        int n = graph.size();
        if (k == 0) {
            if (curr == n - 1) res++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (curr != i && graph[curr][i] == true) {
                dfs(graph, k - 1, i, res);
            }
        }
    }

    int numWays(int n, vector <vector<int>> &relation, int k) {
        int m = relation.size();
        vector <vector<bool>> graph = vector < vector < bool >> (n, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            int x = relation[i][0], y = relation[i][1];
            graph[x][y] = true;
        }
        int res = 0;
        dfs(graph, k, 0, res);
        return res;
    }
};

// 广度优先搜索
// 时间复杂度：O(n^k)
// 空间复杂度：O(n+m+n^k)
class Solution {
public:
    int numWays(int n, vector <vector<int>> &relation, int k) {
        vector <vector<int>> graph(n);
        for (int i = 0; i < relation.size(); i++) {
            int x = relation[i][0], y = relation[i][1];
            graph[x].push_back(y);
        }

        int step = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty() && step != k) {
            int size = q.size();
            step++;
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                for (int j = 0; j < graph[curr].size(); j++) {
                    q.push(graph[curr][j]);
                }
            }
        }

        int res = 0;
        if (step == k) {
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                if (curr == n - 1) res++;
            }
        }

        return res;
    }
};

// 动态规划
// 时间复杂度：O(nk)
// 空间复杂度：O(nk)
class Solution {
public:
    int numWays(int n, vector <vector<int>> &relation, int k) {
        vector <vector<int>> dp(k + 1, vector<int>(n));
        dp[0][0] = 1;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < relation.size(); j++) {
                int x = relation[j][0], y = relation[j][1];
                dp[i + 1][y] += dp[i][x];
            }
        }
        return dp[k][n - 1];
    }
};

// 动态规划
// 时间复杂度：O(nk)
// 空间复杂度：O(n)
class Solution {
public:
    int numWays(int n, vector <vector<int>> &relation, int k) {
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 0; i < k; i++) {
            vector<int> next(n);
            for (int j = 0; j < relation.size(); j++) {
                int x = relation[j][0], y = relation[j][1];
                next[y] += dp[x];
            }
            dp = next;
        }

        return dp[n - 1];
    }
};