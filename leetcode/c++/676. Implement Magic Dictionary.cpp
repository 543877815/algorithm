// 字典树
// 时间复杂度：O(nlogC)
// 空间复杂度：O(nlogC)
class Trie {
public:
    unordered_map<int, Trie*> children;
    bool isEnd = false;
    Trie() {

    }

    void insert(string& dictionary) {
        Trie* curr = this;
        int n = dictionary.size();
        for (int i = 0; i < n; i++) {
            if (curr->children.find(dictionary[i]) == children.end()) {
                curr->children[dictionary[i]] = new Trie();
            }
            curr = curr->children[dictionary[i]];
        }
        curr->isEnd = true;
    }

    bool search(string& searchWord, int index, bool change) {
        int n = searchWord.size();
        if (index == n && change) {
            if (this->isEnd) return true;
            else return false;
        }

        bool result = false;
        if (change) {
            if (this->children.find(searchWord[index]) != this->children.end()) {
                result = result | this->children[searchWord[index]]->search(searchWord, index+1, change);
            }
        } else {
            for (auto &[key, child]: this->children) {
                if (key == searchWord[index]) {
                    result = result | child->search(searchWord, index+1, change);
                } else {
                    result = result | child->search(searchWord, index+1, true);
                }
            }
        }
        return result;
    }
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    Trie* root;
    MagicDictionary() {
        root = new Trie();
    }

    void buildDict(vector<string> dictionary) {
        int n = dictionary.size();
        for (int i = 0; i < n; i++) {
            root-> insert(dictionary[i]);
        }
    }

    bool search(string searchWord) {
        int index = 0;
        return root->search(searchWord, index, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */