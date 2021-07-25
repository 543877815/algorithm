// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        vector<int> res(n+1);
        unordered_map<int, vector<int>> neighbour;
        for (int i = 0; i < n; i++) {
            int x = adjacentPairs[i][0], y = adjacentPairs[i][1];
            neighbour[x].push_back(y);
            neighbour[y].push_back(x);
        }

        vector<int> edge;
        for (auto &x: neighbour){
            if (x.second.size() == 1) {
                edge.push_back(x.first);
            }
        }

        res[0] = edge[0];
        res[n] = edge[1];
        int next = neighbour[res[0]][0];
        for (int i = 1; i < n; i++) {
            auto &a = neighbour[next];
            res[i] = next;
            next = res[i-1] == a[0] ? a[1] : a[0];
        }
        return res;
    }
};