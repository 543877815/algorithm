class Solution {
public:
    string replaceSpace(string s) {
        int len = s.size() - 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                s += "00";
            }
        }
        int index = s.size() - 1;
        for (int i = len; i >= 0; i--) {
            if (s[i] == ' ') {
                s[index--] = '0';
                s[index--] = '2';
                s[index--] = '%';
            } else {
                s[index--] = s[i];
            }
        }
        return s;
    }
};