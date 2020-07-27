// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int length_s = s.size(), length_t = t.size();
        if (length_s == 0) return true;
        int index = 0;
        for (int i = 0; i < length_t; i++) {
            if (t[i] == s[index]) index++;
            if (index == s.size()) return true;
        }
        return false;
    }
};