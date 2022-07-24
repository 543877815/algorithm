// 字典樹
// 时间复杂度：O(1)
// 空间复杂度：O(T26)
class Trie {
public:
    vector<Trie*> children;
    bool isEnd;
    Trie() {
        children = vector<Trie*> (26, nullptr);
        isEnd = false;
    }

    void insert(string &word) {
        Trie* node = this;
        for (auto &ch: word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string &word, int idx) {
        Trie* node = this;
        int n = word.size();
        if (idx == n) {
            if (node->isEnd)return true;
            else return false;
        }
        char ch = word[idx];
        if (ch == '.') {
            bool result = false;
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    result |= node->children[i]->search(word, idx + 1);
                }
            }
            return result;
        } else {
            ch -= 'a';
            if (node->children[ch] == nullptr) return false;
            else return node->children[ch]->search(word, idx + 1);

        }
    }
};

class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }

    void addWord(string word) {
        root->insert(word);
    }

    bool search(string word) {
        return root->search(word, 0);
    }
};
