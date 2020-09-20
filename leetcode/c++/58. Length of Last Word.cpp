// 翻转字符
// 空间复杂度：O(n)
// 时间复杂度：O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        if (n == 0) return 0;
        reverse(s.begin(), s.end());
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') len++;
            if (s[i] == ' ' && len != 0) break;
        }
        return len;
    }
};