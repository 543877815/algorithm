// 前缀树
// 时间复杂度：O(\sum w_i)
// 空间复杂度：O(\sum w_i)
class Trie {
private:
    vector<Trie *> children;
    bool isEnd;
public:
    Trie():children(26), isEnd(false){}
    void insert(string word) {
        Trie* node = this;
        for (auto ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        bool end = true;
        Trie* node = this;
        for (auto ch: word) {
            ch -= 'a';
            node = node->children[ch];
            end &= node->isEnd;
        }
        return end;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* t = new Trie();
        string res;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            t->insert(words[i]);
        }
        for (int i = 0; i < n; i++) {
            if (t->search(words[i])) {
                if ((words[i].size() > res.size() || (words[i].size() == res.size() && words[i] < res))){
                    res = words[i];
                }
            }
        }
        return res;
    }
};