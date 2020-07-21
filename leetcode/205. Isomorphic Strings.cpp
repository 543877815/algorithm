// 使用 map
// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char, char> s_t;
        unordered_map <char, char> t_s;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            if (s_t.find(s[i]) == s_t.end() && t_s.find(t[i]) == t_s.end()) {
                s_t[s[i]] = t[i];
                t_s[t[i]] = s[i];
            } else {
                if (s_t[s[i]] != t[i] || t_s[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};