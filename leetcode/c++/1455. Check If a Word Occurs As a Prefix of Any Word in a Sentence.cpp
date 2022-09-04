// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int startsWith(string s, string sub) {
        return s.find(sub) == 0 ? 1 : 0;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence);
        string word;
        int idx = -1;
        int count = 1;
        while (iss >> word) {
            if (startsWith(word, searchWord)) {
                idx = count;
                break;
            }
            count++;
        }

        return idx;
    }
};