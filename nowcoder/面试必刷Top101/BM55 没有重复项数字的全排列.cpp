// 时间复杂度：O(2^n*n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<bool> used;
    vector<vector<int>> res;
    void dfs(vector<int> &num, vector<int> &tmp) {
        int n = num.size();
        if (tmp.size() == n) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                tmp.push_back(num[i]);
                used[i] = true;
                dfs(num, tmp);
                used[i] = false;
                tmp.pop_back();
            }
        }

    }

    vector<vector<int> > permute(vector<int> &num) {
        int n = num.size();
        if (n == 0) return res;
        vector<int> tmp;
        used = vector<bool> (n, false);
        dfs(num, tmp);
        return res;
    }
};