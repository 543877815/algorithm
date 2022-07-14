// 哈希表
// 时间复杂度：O(w^3)
// 空间复杂度：O(w^3)
class WordFilter {
public:
    unordered_map<string, int> hashmap;

    WordFilter(vector <string> &words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            int m = words[i].size();
            for (int preLength = 1; preLength <= m; preLength++) {
                for (int postLength = 1; postLength <= m; postLength++) {
                    string query = words[i].substr(0, preLength) + "#" + words[i].substr(m - postLength);
                    hashmap[query] = i;
                }
            }
        }
    }

    int f(string pref, string suff) {
        string query = pref + "#" + suff;
        if (hashmap.count(query)) {
            return hashmap[query];
        } else return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */