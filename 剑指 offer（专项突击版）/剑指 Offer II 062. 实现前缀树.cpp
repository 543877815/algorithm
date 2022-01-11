// 时间复杂度：O(S), S是插入或查询的字符串的长度
// 空间复杂度：O(T*26) T是所有插入字符串的长度之和
class Node {
public:
    unordered_map<char, Node*> child;
    bool isEnd;
    Node() {
        isEnd = false;
    }


    void insert(string& word, int index) {
        if (index == word.size()) {
            isEnd = true;
            return;
        }
        char s = word[index];
        if (child.find(s) == child.end()) {
            child[s] = new Node();
        }
        child[s]->insert(word, index+1);
    }

    bool search(string& word, int index) {
        if (index == word.size() && isEnd) return true;
        char s = word[index];
        if (child.find(s) == child.end()) return false;
        else return child[s]->search(word, index+1);

    }

    bool startsWith(string& prefix, int index) {
        if (index == prefix.size()) return true;
        char s = prefix[index];
        if (child.find(s) == child.end()) return false;
        else return child[s]->startsWith(prefix, index+1);
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node* root;

    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int index = 0;
        root->insert(word, index);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int index = 0;
        return root->search(word, index);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int index = 0;
        return root->startsWith(prefix, index);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */