// Prim 算法
// 时间复杂度：O(n + eloge)
// 空间复杂度：O(n + e)
// 例子见 1135. 最低成本联通所有城市 https://leetcode.cn/problems/connecting-cities-with-minimum-cost/

class Solution {
public:
    int minimumCost(int n, vector <vector<int>> &connections) {
        int m = connections.size();
        auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b) {  // [开销, 目的]
            return a.first > b.first;
        };
        priority_queue < pair < int, int >, vector < pair < int, int >>, decltype(cmp) > pq(cmp);
        vector < vector < pair < int, int>>> edges(n + 1);
        for (int i = 0; i < m; i++) {
            int start = connections[i][0], end = connections[i][1], weight = connections[i][2];
            edges[start].emplace_back(end, weight);
            edges[end].emplace_back(start, weight);
        }

        set<int> s;
        int res = 0;
        pq.push(make_pair(0, 1));
        while (!pq.empty() && s.size() != n) {
            auto [weight, node] = pq.top();
            pq.pop();
            if (s.find(node) == s.end()) {
                s.insert(node);
                res += weight;
                for (auto [next_node, weight]: edges[node]) {
                    pq.push(make_pair(weight, next_node));
                }
            }
        }

        return s.size() == n ? res : -1;
    }
};

int main() {
//    int n = 3;
//    vector<vector<int>> connections = {{1, 2, 5},
//                                      {1, 3, 6},
//                                      {2, 3, 1}};

    int n = 4;
    vector<vector<int>> connections = {{1, 2, 3},
                                       {3, 4, 4}};
    auto a = new Solution();
    cout << a->minimumCost(n, connections);
}