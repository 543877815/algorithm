// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string tmp = s.substr(0, n);
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            s[i] = i < s.size() - n ? s[i+n] : tmp[index++];
        }
        return s;
    }
};