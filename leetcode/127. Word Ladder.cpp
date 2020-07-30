// 超出时间限制
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        if (beginWord == endWord || wordList.empty()) return 0;

        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        unordered_set<string> visited;
        vector<unordered_set<char>> chara_set(endWord.size());
        for (string word : wordList) {
            for (int i = 0; i < word.size(); i++) {
                if (word[i] == beginWord[i]) continue;
                chara_set[i].insert(word[i]);
            }
        }

        while (!q.empty()) {
            string str = q.front().first;
            int step = q.front().second;
            q.pop();
            for (int i = 0; i < endWord.size(); ++i) {
                string tmp = str;
                for (auto chara : chara_set[i]) {
                    tmp[i] = chara;
                    if (find(wordList.begin(), wordList.end(), tmp) == wordList.end()) continue;
                    if (tmp == endWord) return step + 1;
                    if (visited.find(tmp) == visited.end()){
                        q.push(make_pair(tmp, step + 1));
                        visited.insert(tmp);
                    }
                }
            }
        }
        return 0;
    }
};