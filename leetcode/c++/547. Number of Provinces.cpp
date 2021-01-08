// 深度优先搜索
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    vector<bool> visited;
    int res = 0;

    void dfs(vector <vector<int>> &isConnected, const int index) {
        for (int i = 0; i < isConnected[index].size(); i++) {
            if (isConnected[index][i] == 1 && i != index && !visited[i]) {
                visited[i] = true;
                dfs(isConnected, i);
            }
        }
    }

    int findCircleNum(vector <vector<int>> &isConnected) {
        int n = isConnected.size();
        visited = vector<bool>(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(isConnected, i);
                res++;
            }
        }
        return res;
    }
};

// 广度优先搜索
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    int findCircleNum(vector <vector<int>> &isConnected) {
        queue<int> q;
        int n = isConnected.size();
        int res = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    int tmp = q.front();
                    q.pop();
                    for (int i = 0; i < n; i++) {
                        if (!visited[i] && isConnected[tmp][i] == 1) {
                            visited[i] = true;
                            q.push(i);
                        }
                    }
                }
                res++;
            }
        }
        return res;
    }
};


// 并查集
// 时间复杂度：O(n^2logn)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> fa;
    vector<int> rank;

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    void merge(int i, int j) {
        int x = find(i), y = find(j);
        if (rank[x] <= rank[y]) fa[x] = y;
        else fa[y] = x;
        if (rank[x] == rank[y] && x != y) rank[y]++;
    }

    int findCircleNum(vector <vector<int>> &isConnected) {
        int n = isConnected.size();
        fa = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
            rank[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    merge(i, j);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (fa[i] == i) res++;
        }

        return res;
    }
};