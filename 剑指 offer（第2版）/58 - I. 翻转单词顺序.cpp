// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    string reverseWords(string s) {
        s.erase(0,s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
        reverse(s.begin(), s.end());
        int left = 0, right = 0;
        while (right < s.size()) {
            if (s[left] != ' ') {
                while (right < s.size() && s[right] != ' ') right++;
                reverse(s.begin() + left, s.begin() + right);
                left = right;
            } else {
                while (right < s.size() && s[right] == ' ') right++;
                s.erase(remove(s.begin() + left + 1, s.begin() + right, ' '), s.begin() + right);
                left += 1;
                right = left;
            }
        }
        return s;
    }
};