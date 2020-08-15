// 时间复杂度：O(n!)
// 空间房租的：O(n^2)

class Solution {
private:
    vector <string> res;
    vector<bool> visited;

    void DFS(string &s, string &ans) {
        if (s.size() == ans.size()) {
            res.push_back(ans);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && s[i] == s[i - 1] && visited[i - 1]) continue;
            if (!visited[i]) {
                visited[i] = true;
                ans.push_back(s[i]);
                DFS(s, ans);
                ans.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    vector <string> permutation(string s) {
        int n = s.size();
        if (n == 0) return res;
        sort(s.begin(), s.end());
        visited = vector<bool>(n, false);
        string str;
        DFS(s, str);
        return res;
    }
};