// 回溯
// 空间复杂度：O(n)
// 时间复杂度：O(4^n)
class Solution {
public:
    vector<bool> visited;

    bool backtrack(vector<int> &matchsticks, vector<int> &edges, int index, int &len) {
        if (matchsticks.size() == index) return true;
        for (int i = 0; i < 4; i++) {
            edges[i] += matchsticks[index];
            if (edges[i] <= len && backtrack(matchsticks, edges, index + 1, len)) return true;
            edges[i] -= matchsticks[index];
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks) {
        int n = matchsticks.size();
        visited = vector<bool>(n, false);
        vector<int> edges(4, 0);
        int totalLen = 0;
        for (int i = 0; i < n; i++) {
            totalLen += matchsticks[i];
        }

        if (totalLen % 4 != 0) return false;
        int len = totalLen / 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        return backtrack(matchsticks, edges, 0, len);
    }
};