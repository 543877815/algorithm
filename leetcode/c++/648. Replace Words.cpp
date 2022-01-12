// 前缀哈希
// 时间复杂度：O(n + m)
// 空间复杂度：O(n)
class Solution {
public:
    string replaceWords(vector <string> &dictionary, string sentence) {
        int n = sentence.size();
        unordered_set <string> myset(dictionary.begin(), dictionary.end());
        string res;
        string sub_str;
        int i = 0;
        while (i < n) {
            while (i < n && sentence[i] != ' ') {
                sub_str += sentence[i++];
                if (myset.find(sub_str) != myset.end()) break;
            }
            res = res + sub_str + ' ';
            sub_str = "";
            while (i < n && sentence[i] != ' ') {
                i++;
            }
            i++;
        }
        res = res.substr(0, res.size() - 1);
        return res;
    }
};

// 前缀树
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Trie {
public:
    unordered_map<char, Trie *> children;
    string word;

    Trie() {
        word = "";
    }

    void insert(string &dictionary) {
        int n = dictionary.size();
        Trie *curr = this;
        for (int i = 0; i < n; i++) {
            if (curr->children.find(dictionary[i]) == curr->children.end()) {
                curr->children[dictionary[i]] = new Trie();
            }
            curr = curr->children[dictionary[i]];
        }
        curr->word = dictionary;
    }

    string search(string &dictionary) {
        int n = dictionary.size();
        Trie *curr = this;
        for (int i = 0; i < n; i++) {
            if (curr->children.find(dictionary[i]) != curr->children.end()) {
                curr = curr->children[dictionary[i]];
            } else break;
            if (curr->word != "") return curr->word;
        }
        return dictionary;
    }
};

class Solution {
public:
    vector <string> Split(string &str) {
        vector <string> res;

        //转化成为stringsteam对象
        stringstream ss(str);

        string curr;

        while (std::getline(ss, curr, ' ')) {
            if (curr.size() > 0) {
                res.push_back(curr);
            }
        }
        return res;
    }

    string replaceWords(vector <string> &dictionary, string sentence) {
        int n = dictionary.size();
        Trie *root = new Trie();
        for (int i = 0; i < n; i++) {
            root->insert(dictionary[i]);
        }

        vector <string> words = Split(sentence);
        int m = words.size();
        string res;
        for (int i = 0; i < m; i++) {
            res += root->search(words[i]);
            if (i < m - 1) res += " ";
        }

        return res;
    }
};