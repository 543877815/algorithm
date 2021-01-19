// 并查集
// 时间复杂度：O(nlogn)
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

    vector <vector<string>> accountsMerge(vector <vector<string>> &accounts) {

        // hash表构建
        unordered_map<string, int> email2Id;
        unordered_map<int, string> emailId2name;
        unordered_map<int, string> Id2email;
        int emailId = 0;
        int n = accounts.size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (!email2Id.count(accounts[i][j])) {
                    emailId2name[emailId] = accounts[i][0];
                    Id2email[emailId] = accounts[i][j];
                    email2Id[accounts[i][j]] = emailId++;
                }
            }
        }

        // 并查集初始化
        fa.resize(emailId);
        iota(fa.begin(), fa.end(), 0);
        rank = vector<int>(emailId, 1);

        // 构建并查集
        for (int i = 0; i < n; i++) {
            int x = email2Id[accounts[i][1]];
            for (int j = 2; j < accounts[i].size(); j++) {
                int y = email2Id[accounts[i][j]];
                merge(x, y);
            }
        }

        // 构造并查集根对应的节点集
        unordered_map<int, vector<int>> fa2emailIds;
        for (int i = 0; i < emailId; i++) {
            int x = find(fa[i]);
            if (!fa2emailIds.count(x)) fa2emailIds[x] = {i};
            else fa2emailIds[x].emplace_back(i);
        }

        // 将结果整理放入答案
        vector <vector<string>> res;
        for (auto &[faId, aId] : fa2emailIds) {
            string name = emailId2name[faId];
            vector <string> tmp = {name};
            for (auto &elem : aId) {
                tmp.emplace_back(Id2email[elem]);
            }
            sort(tmp.begin() + 1, tmp.end());
            res.push_back(tmp);
        }

        return res;
    }
};