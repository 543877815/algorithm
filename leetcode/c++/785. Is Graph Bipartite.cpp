// �����������
// ʱ�临�Ӷȣ�O(n+m)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    vector<bool> color;
    vector<bool> visited;
    int res = true;

    void traverse(vector <vector<int>> graph, int v) {
        if (!res) return;
        visited[v] = true;
        for (int w: graph[v]) {
            if (!visited[w]) {
                color[w] = !color[v];
                traverse(graph, w);
                if (!res) return;
            } else {
                if (color[w] == color[v]) {
                    res = false;
                    return;
                }
            }
        }
    }

    bool isBipartite(vector <vector<int>> &graph) {
        int n = graph.size();
        visited = vector<bool>(n, false);
        color = vector<bool>(n, false);
        for (int v = 0; v < n; v++) {
            if (!visited[v] && res) {
                traverse(graph, v);
            }
        }

        return res;
    }
};

// �����������
// ʱ�临�Ӷȣ�O(n+m)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    vector<bool> color;
    vector<bool> visited;

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visited = vector<bool>(n, false);
        color = vector<bool>(n, false);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    int top = q.front();
                    q.pop();
                    for (int v : graph[top]) {
                        if (!visited[v]) {
                            color[v] = !color[top];
                            q.push(v);
                            visited[v] = true;
                        } else {
                            if (color[v] == color[top]) {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};

// ���鼯
// ʱ�临�Ӷȣ�O(n+e)
// �ռ临�Ӷȣ�O(n)
class Solution {
private:
    vector<int> fa;
    vector<int> rank;
    inline void init(int n) {
        fa.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            fa[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    // �ȣ��Ե�ǰ���Ϊ���ڵ�������ĸ߶�(rank)
    inline void merge(int i, int j) {
        int x = find(i), y = find(j);    //���ҵ��������ڵ�
        if (rank[x] <= rank[y])
            fa[x] = y;
        else
            fa[y] = x;
        if (rank[x] == rank[y] && x != y)
            rank[y]++;                   //��������ͬ�Ҹ��ڵ㲻ͬ�����µĸ��ڵ�����+1
    }
public:


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        init(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            visited[i] = true;
            for (int v: graph[i]) {
                if (find(i) == find(v)) return false;
                merge(graph[i][0], v);
            }
        }
        return true;
    }
};