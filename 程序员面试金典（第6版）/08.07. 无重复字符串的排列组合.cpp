// 时间复杂度：O(2^n)
// 空间复杂度：O(2^n)
class Solution {
private:
    vector<bool> visited;
    vector <string> res;

public:
    void DFS(string &S, string &str) {
        if (str.size() == S.size()) {
            res.emplace_back(str);
            return;
        }
        for (int i = 0; i < S.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                str.push_back(S[i]);
                DFS(S, str);
                str.pop_back();
                visited[i] = false;
            }
        }
    }

    vector <string> permutation(string S) {
        string str;
        visited = vector<bool>(S.size(), false);
        DFS(S, str);
        return res;
    }
};