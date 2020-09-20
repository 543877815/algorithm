// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if (n == 0) return s;
        int left = 0, right = 0;

        while (right < n) {
            if (s[right] != ' ') right++;
            else {
                reverse(s.begin() + left, s.begin() + right);
                right++;
                while (right < n && s[right] == ' ') {
                    right++;
                }
                left = right;
            }
        }
        if (left != right) reverse(s.begin() + left, s.begin() + right);

        return s;
    }
};