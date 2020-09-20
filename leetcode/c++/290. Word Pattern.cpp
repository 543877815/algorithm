// 使用 map
// 空间复杂度：O(m+n)
// 时间复杂度：O(m+n)

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> pattern_str;
        unordered_map<string, char> str_pattern;
        string tmp;
        int index = 0;
        for (char i : pattern) {
            if (index == str.size()) return false;
            tmp = "";
            for (int j = index; j < str.size(); j++) {
                index++;
                if (str[j] != ' ') tmp += str[j];
                else break;
            }
            if (pattern_str.find(i) == pattern_str.end() && str_pattern.find(tmp) == str_pattern.end()) {
                pattern_str[i] = tmp;
                str_pattern[tmp] = i;
            } else {
                if (pattern_str[i] != tmp || str_pattern[tmp] != i) return false;
            }
        }
        if (index < str.size()) return false;
        return true;
    }
};
