// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int findClosest(vector <string> &words, string word1, string word2) {
        int last_word1 = -1;
        int last_word2 = -1;
        int n = words.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (words[i] == word1) {
                if (last_word2 != -1) {
                    res = min(res, i - last_word2);
                }
                last_word1 = i;
            }
            if (words[i] == word2) {
                if (last_word1 != -1) {
                    res = min(res, i - last_word1);
                }
                last_word2 = i;
            }
        }

        return res;
    }
};