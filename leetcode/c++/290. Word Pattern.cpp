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


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int space = 0;
        for (auto &x : s) {
            if (x == ' ') space++;
        }
        if (space == 0) return pattern.size() == 1;
        if (space >= pattern.size()) return false;
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        string tmp;
        for (auto &x : pattern) {
            int index = s.find(' ');
            if (index != -1) {
                tmp = s.substr(0, index);
                s = s.substr(index + 1);
                if (s2p.count(tmp) == 0) s2p[tmp] = x;
                else if (s2p[tmp] != x) return false;
                if (p2s.count(x) == 0) p2s[x] = tmp;
                else if (p2s[x] != tmp) return false;
            } else if (p2s.count(x) != 0 && p2s[x] != s) return false;
            else if (s2p.count(s) != 0 && s2p[s] != x) return false;
        }

        return true;
    }
};