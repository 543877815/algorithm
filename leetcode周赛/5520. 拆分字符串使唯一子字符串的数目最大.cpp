// 回溯算法
// 时间复杂度：O(2^n)
// 空间复杂度：O(n)
class Solution {
private:
    int ans = 0;
    unordered_set <string> s_set;

public:
    void DFS(string &s, int index) {
        if (s.size() - index + s_set.size() <= ans) return;
        if (index == s.size()) {
            ans = max(ans, (int) s_set.size());
            return;
        }

        string temp;
        for (int i = index; i < s.size(); i++) {
            temp += s[i];
            if (s_set.find(temp) == s_set.end()) {
                s_set.insert(temp);
                DFS(s, i + 1);
                s_set.erase(temp);
            }
        }
    }

    int maxUniqueSplit(string s) {
        DFS(s, 0);
        return ans;
    }
};