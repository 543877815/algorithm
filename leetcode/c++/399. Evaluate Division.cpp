// 并查集
// 时间复杂度：O((N+Q)logA)
// 构造并查集：O(NlogA)，这里N为输入方程equations的长度
// 查询并查集：O(QlogA)，这里Q为查询数组queries的长度
// 空间复杂度：O(A)
class Solution {
public:
    vector<int> fa;
    vector<double> weight;
    unordered_map<string, int> hashMap;

    // 路径压缩
    int find(int x) {
        // weight[x] *= weight[fa[x]];
        // return x == fa[x] ? x : (fa[x] = find(fa[x]));
        if (fa[x] != x) {
            int father = find(fa[x]);
            weight[x] = weight[x] * weight[fa[x]];
            fa[x] = father;
        }
        return fa[x];
    }

    void merge(int i, int j, double val) {
        int x = find(i), y = find(j);
        fa[x] = y;
        weight[x] = val * weight[j] / weight[i];
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        int id = 0;
        vector<double> res;

        // 构造string2int的映射
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                if (hashMap.count(equations[i][j]) == 0) {
                    hashMap[equations[i][j]] = id++;
                }
            }
        }

        fa = vector<int>(id);
        weight = vector<double>(id, 1.0);

        // 并查集初始化
        for (int i = 0; i < id; i++) {
            fa[i] = i;
        }

        // 并查集构造
        for (int i = 0; i < n; i++) {
            int x = hashMap[equations[i][0]];
            int y = hashMap[equations[i][1]];
            merge(x, y, values[i]);
        }

        // query
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            double result = -1.0;
            if (hashMap.count(queries[i][0]) != 0 && hashMap.count(queries[i][1]) !=0) {
                int x = hashMap[queries[i][0]];
                int y = hashMap[queries[i][1]];
                int fx = find(x), fy = find(y);
                if (fx == fy) result = weight[x] / weight[y];
            }
            res.push_back(result);
        }
        return res;
    }
};