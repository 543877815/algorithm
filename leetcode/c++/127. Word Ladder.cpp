// 超出时间限制
// 图论 广度优先搜索s
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


// 超出时间限制
// 图论 广度优先搜索
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        if (beginWord == endWord || wordList.empty()) return 0;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(beginWord) != wordSet.end()) wordSet.erase(beginWord);
        if(wordSet.find(endWord) == wordSet.end()) return 0;
        vector<string> visited;
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        while (!q.empty()) {
            string curr_word = q.front().first;
            int length = q.front().second;
            q.pop();
            visited.clear();
            for (string word : wordSet) {
                if (word.size() != curr_word.size()) continue;
                int diff = 0;
                for (int i = 0; i < word.size(); i++) {
                    if (word[i] != curr_word[i]) diff++;
                    if (diff > 1) break;
                }
                if (diff == 1) {
                    if (word == endWord) return length+1;
                    q.push(make_pair(word, length+1));
                    visited.push_back(word);
                }
            }
            for (string word : visited){
                wordSet.erase(word);
            }
        }
        return 0;
    }
};



// 优化
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        if (beginWord == endWord || wordList.empty()) return 0;
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        while (!q.empty()) {
            string str = q.front().first;
            int step = q.front().second;
            q.pop();

            for (int i = 0; i < endWord.size(); ++i) {
                string tmp = str;
                for (char c = 'a'; c <= 'z'; c++) {
                    tmp[i] = c;
                    if (wordSet.find(tmp) != wordSet.end()){
                        if (tmp == endWord) return step + 1;
                        q.push(make_pair(tmp, step + 1));
                        wordSet.erase(tmp);
                    }
                }
            }
        }
        return 0;
    }
};