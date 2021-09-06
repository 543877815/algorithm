// 做一个 hash mapping
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool isAlienSorted(vector <string> &words, string order) {
        unordered_map<int, int> record;
        int m = order.size();
        for (int i = 0; i < m; i++) {
            record[order[i]] = i;
        }

        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                words[i][j] = record[words[i][j]];
            }
        }

        for (int i = 1; i < n; i++) {
            if (words[i] < words[i - 1]) return false;
        }

        return true;
    }
};