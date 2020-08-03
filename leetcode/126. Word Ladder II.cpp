// BFS，N为wordList长度，C为列表中单词的长度
// 时间复杂度：O(n^2c)
// 空间复杂度：O(n^2)
class Solution {
private:
    unordered_map<string, int> wordId; // 单词到id的映射
    vector<string> idWord;             // 单词的集合
    vector<vector<int>> edges;         // 单词节点之间的可达性记录
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        if (beginWord == endWord || wordList.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return res;
        int id = 0;
        for (string word : wordList) {
            if (!wordId.count(word)) {
                wordId[word] = id++;
                idWord.push_back(word);
            }
        }
        if (!wordId.count(beginWord)) {
            wordId[beginWord] = id++;
            idWord.push_back(beginWord);
        }
        edges.resize(idWord.size());
        for (int i = 0; i < idWord.size(); i++) {
            for (int j = i + 1; j < idWord.size(); j++) {
                if (check(idWord[i], idWord[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        const int dest = wordId[endWord];
        queue<vector<int>> q; // 记录路径
        q.push(vector<int>{wordId[beginWord]});
        vector<int> cost(id, INT_MAX);  // 记录 beginWord 到达某个单词的距离
        cost[wordId[beginWord]] = 0;
        while(!q.empty()) {
            vector<int> now = q.front();
            q.pop();
            int last = now.back();
            if (last == dest) {
                vector<string> tmp;
                for (int index : now) {
                    tmp.push_back(idWord[index]);
                }
                res.push_back(tmp);
            } else {
                for (int i = 0; i < edges[last].size(); i++) {
                    int to = edges[last][i];   // 遍历 last 可达结点
                    if (cost[last] + 1 <= cost[to]) {
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);
                        tmp.push_back(to);
                        q.push(tmp);
                    }

                }
            }
        }

        return res;
    }

    bool check(const string &str1, const string &str2) {
        int differences = 0;
        for (int i = 0; i < str1.size() && differences < 2; i++) {
            if (str1[i] != str2[i]) {
                differences++;
            }
        }
        return differences == 1;
    }
};


// 直接使用string到string的映射
// 时间更长，空间更大
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<vector<string>> res;
        if (beginWord == endWord || wordList.empty() ||
            find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return res;
        unordered_map<string, vector<string>> edges;         // 单词节点之间的可达性记录
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) wordList.push_back(beginWord);
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (check(wordList[i], wordList[j])) {
                    edges[wordList[i]].push_back(wordList[j]);
                    edges[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        queue<vector<string>> q;
        q.push(vector<string>{beginWord});

        unordered_map<string, int> cost;
        for (const auto &word : wordList) cost[word] = INT_MAX;
        cost[beginWord] = 0;
        while (!q.empty()) {
            vector<string> now = q.front();
            q.pop();
            string last = now.back();
            if (last == endWord) {
                res.push_back(now);
            } else {
                for (const auto &word : edges[last]) {
                    if (cost[last] + 1 <= cost[word]) {
                        cost[word] = cost[last] + 1;
                        vector<string> tmp(now);
                        tmp.push_back(word);
                        q.push(tmp);
                    }
                }
            }
        }
        return res;
    }

    // 判断单词可达
    bool check(const string &str1, const string &str2) {
        int differences = 0;
        for (int i = 0; i < str1.size() && differences < 2; i++) {
            if (str1[i] != str2[i]) {
                differences++;
            }
        }
        return differences == 1;
    }
};
