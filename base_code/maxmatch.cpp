// �������㷨+���ƥ�����С�㸲������
// ʱ�临�Ӷȣ�O(nm)
// �ռ临�Ӷȣ�O(n)
// case: https://www.jb51.net/article/215059.htm
// code reference: https://blog.csdn.net/qq_25379821/article/details/83721379
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> cx;  //cx[i]��ʾX��i��ƥ���Y������ı��
    vector<int> cy;  //cy[i]��ʾY��i��ƥ���X������ı��
public:
    bool dfs(vector<vector<int>> &connections, vector<bool> &visited, int u, int n) {
        for (int v: connections[u]) {
            if (!visited[v]) {
                visited[v] = true;
                // ���û��ƥ����߳���ȥ�ҵ�����·��
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