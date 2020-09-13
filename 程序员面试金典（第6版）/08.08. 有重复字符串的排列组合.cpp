// 时间复杂度：O(2^n)
// 空间复杂度：O(2^n)
class Solution {
private:
    vector <string> res;
    vector<bool> visited;

    void DFS(string &S, string &str) {
        if (str.size() == S.size()) {
            res.emplace_back(str);
            return;
        }

        for (int i = 0; i < S.size(); i++) {
            if (i > 0 && S[i] == S[i - 1] && visited[i - 1]) continue;
            if (!visited[i]) {
                visited[i] = true;
                str.push_back(S[i]);
                DFS(S, str);
                str.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    vector <string> permutation(string S) {
        sort(S.begin(), S.end());
        visited = vector<bool>(S.size(), false);
        string str;
        DFS(S, str);
        return res;
    }
};