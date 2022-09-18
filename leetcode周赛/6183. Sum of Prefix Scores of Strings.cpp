// 字典树
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Trie {
private:
    vector<Trie*> children;
    bool isEnd;
    int val;


public:
    /** Initialize your data structure here. */
    Trie():children(26), isEnd(false), val(0) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (auto ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr)
                node->children[ch] = new Trie();
            node = node->children[ch];
            node->isEnd = true;
            node->val++;
        }
    }

    /** Returns if the word is in the trie. */
    int searchPrefix(string word) {
        Trie* node = this;
        int res = 0;
        for(auto ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr)
                return 0;
            node = node->children[ch];
            res += node->val;
        }
        return res;
    }


};



class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *root = new Trie();
        int n = words.size();
        unordered_map<string, int> record;
        for (int i = 0; i < n; i++) {
            root->insert(words[i]);
        }
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            res[i] += root->searchPrefix(words[i]);

        }
        return res;
    }
};