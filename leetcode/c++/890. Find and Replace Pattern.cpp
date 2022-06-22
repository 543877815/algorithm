// 哈希表构造双射
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector <string> findAndReplacePattern(vector <string> &words, string pattern) {
        vector <string> res;
        int n = words.size();
        int m = pattern.size();
        for (int i = 0; i < n; i++) {
            if (words[i].size() != m) continue;
            unordered_map<char, char> a2b;
            unordered_map<char, char> b2a;
            bool add = true;
            for (int j = 0; j < m; j++) {
                char a = words[i][j];
                char b = pattern[j];
                if (a2b.find(a) == a2b.end() && b2a.find(b) == b2a.end()) {
                    a2b[a] = b;
                    b2a[b] = a;
                } else if (a2b.find(a) == a2b.end() || b2a.find(b) == b2a.end()) {
                    add = false;
                    break;
                } else if (a2b[a] != b || b2a[b] != a) {
                    add = false;
                    break;
                }
            }

            if (add) res.push_back(words[i]);
        }

        return res;
    }
};