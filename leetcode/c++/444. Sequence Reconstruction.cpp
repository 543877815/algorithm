// Õÿ∆À≈≈–Ú
//  ±º‰∏¥‘”∂»£∫O(m+n)
// ø’º‰∏¥‘”∂»£∫O(m+n)
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        int m = sequences.size();
        vector<int> inDegree(n+1, 0);
        unordered_map<int, vector<int>> hashmap;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < sequences[i].size(); j++) {
                inDegree[sequences[i][j]]++;
                hashmap[sequences[i][j-1]].push_back(sequences[i][j]);
            }
        }
        stack<int> sk;

        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                sk.push(i);
            }
        }

        int idx = 0;
        while (!sk.empty()) {
            if (sk.size() > 1) return false;
            int next = sk.top();
            if (next != nums[idx]) return false;
            else idx++;
            sk.pop();
            for (auto &num: hashmap[next]) {
                inDegree[num]--;
                if (inDegree[num] == 0) sk.push(num);
            }
        }

        return idx == n;
    }
};