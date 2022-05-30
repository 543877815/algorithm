// 时间复杂度：O(2^n*n)
// 空间复杂度：O(n)
class Solution {
public:
    vector <vector<int>> res;

    void dfs(vector<int> &num, vector<int> &tmp, vector<bool> &used) {
        int n = num.size();
        if (tmp.size() == n) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (i && num[i] == num[i - 1] && !used[i - 1]) continue;
            if (!used[i]) {
                used[i] = true;
                tmp.push_back(num[i]);
                dfs(num, tmp, used);
                tmp.pop_back();
                used[i] = false;
            }
        }
    }

    vector <vector<int>> permuteUnique(vector<int> &num) {
        int n = num.size();
        if (n == 0) return res;
        sort(num.begin(), num.end());
        vector<int> tmp;
        vector<bool> used(n, false);
        dfs(num, tmp, used);
        return res;

    }
};