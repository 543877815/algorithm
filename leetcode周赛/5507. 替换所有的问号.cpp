// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    string modifyString(string s) {
        int tmp, j;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                tmp = i;
                while (tmp < s.size() && s[tmp] == '?') tmp++;
                if (i == 0 && tmp == s.size()) {  // 全是?
                    s[0] = 'a';
                }
                for (j = tmp - 1; j >= i; j--) {
                    int index = j + 1 == s.size() ? 0 : j + 1;
                    s[j] = s[index] - 1 > 'a' ? s[index] - 1 : s[index] - 1 + 25;
                }
                if (i > 0 && s[i] == s[i - 1]) {
                    s[i] = s[i - 1] - 1 > 'a' ? s[i - 1] - 1 : s[i - 1] - 1 + 25;
                }
            }
        }
        return s;
    }
};