// 回溯
// 时间复杂度：O(k * C(n, k))
// 空间复杂度：O(k)
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& tmp, int n , int k, int index) {
        if (tmp.size() == k) res.push_back(tmp);
        else if (tmp.size() > k || index > n) return;
        for (int i = index; i <= n; i++) {
            tmp.push_back(i);
            dfs(tmp, n, k, i+1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        dfs(tmp, n, k, 1);
        return res;

    }
};