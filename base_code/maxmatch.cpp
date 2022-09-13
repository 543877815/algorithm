// 匈牙利算法+最大匹配和最小点覆盖问题
// 时间复杂度：O(nm)
// 空间复杂度：O(n)
// case: https://www.jb51.net/article/215059.htm
// code reference: https://blog.csdn.net/qq_25379821/article/details/83721379
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> cx;  //cx[i]表示X部i点匹配的Y部顶点的编号
    vector<int> cy;  //cy[i]表示Y部i点匹配的X部顶点的编号
public:
    bool dfs(vector<vector<int>> &connections, vector<bool> &visited, int u, int n) {
        for (int v: connections[u]) {
            if (!visited[v]) {
                visited[v] = true;
                // 如果没被匹配或者尝试去找到增广路径
                if (cy[v] == -1 || dfs(connections, visited, cy[v], n)) {
                    cy[v] = u;
                    cx[u] = v;
                    return true;
                }
            }
        }
        return false;
    }

    int maxmatch(vector<vector<int>> &edges, int n) {
        vector<vector<int>> connections(n);
        for (int i = 0; i < n; i++) {
            int a = edges[i][0], b = edges[i][1];
            connections[a].push_back(b);
        }

        int res = 0;
        cx = vector<int>(n, -1);
        cy = vector<int>(n, -1);
        for (int i = 0; i < n; i++) {
            if (cx[i] == -1) {
                vector<bool> visited(n, false);
                res += dfs(connections, visited, i, n);
            }
        }
        return res;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> edges = {
            {0, 1},
            {0, 3},
            {1, 1},
            {2, 0},
            {2, 2},
            {3, 3}
    };
    auto a = new Solution();
    cout << a->maxmatch(edges, n);
}