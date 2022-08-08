// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        unordered_set<string> myset;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int idx = words[i].find(words[j]);
                if (idx != string::npos) myset.insert(words[j]);
                idx = words[j].find(words[i]);
                if (idx != string::npos) myset.insert(words[i]);
            }
        }
        vector<string> res(myset.begin(), myset.end());
        return res;
    }
};