// 时间复杂度：O(n)
// 空间复杂度：O(2n)
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        s2 = s2 + s2;
        return s2.find(s1) != -1;
    }
};


// KMP
// 时间复杂度：O(2n)
// 空间复杂度：O(2n)
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        s2 = s2 + s2;
        return kmp(s2, s1);
    }

    bool kmp(string &query, string &pattern) {
        int n = query.size(), m = pattern.size();
        vector<int> next(m, -1);
        int j = 0, i = -1;
        while (j < m - 1) {
            if (i == -1 || pattern[i] == pattern[j])
                next[++j] = next[++i];
            else
                i = next[i];
        }

        j = 0;
        i = 0;
        while (i < n && j < m) {
            if (j == -1 || query[i] == pattern[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        return j == m;
    }
};