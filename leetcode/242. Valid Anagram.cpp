// 使用map
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> sMat;
        for(int i = 0; i < s.size(); i++) {
            sMat[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++) {
            sMat[t[i]]--;
        }
        for(int i = 0; i < t.size(); i++) {
            if(sMat[t[i]] != 0) return false;
        }
        return true;
    }
};