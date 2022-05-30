// 时间复杂度：O(2^n*n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<string> res;
    vector<bool> used;
    void dfs(string& str, string &tmp) {
        int n = str.size();
        if (n == tmp.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (i && str[i] == str[i-1] && !used[i - 1]) continue;
            if (!used[i]) {
                used[i] = true;
                tmp.push_back(str[i]);
                dfs(str, tmp);
                tmp.pop_back();
                used[i] = false;
            }
        }
    }

    vector<string> Permutation(string str) {
        int n = str.size();
        if (n == 0) return res;
        used = vector<bool>(n, false);
        sort(str.begin(), str.end());
        string tmp = "";
        dfs(str, tmp);
        return res;
    }
};