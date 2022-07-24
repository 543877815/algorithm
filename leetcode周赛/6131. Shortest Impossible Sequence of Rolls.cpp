// 脑筋急转弯
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int shortestSequence(vector<int> &rolls, int k) {
        int n = rolls.size();
        vector<bool> vis(k);
        int cnt = 0, ans = 1;
        for (int x: rolls)
            if (!vis[x - 1]) {
                vis[x - 1] = true;
                cnt++;
                if (cnt == k) vis.clear(), vis.resize(k), cnt = 0, ans++;
            }
        return ans;
    }
};

