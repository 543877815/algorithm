// 枚举前缀进行删除
// 时间复杂度：O(sum(ni^2))
// 空间复杂度：O(sum(ni))
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> good(words.begin(), words.end());
        for (const string& word: words) {
            for (int k = 1; k < word.size(); ++k) {
                good.erase(word.substr(k));
            }
        }

        int ans = 0;
        for (const string& word: good) {
            ans += word.size() + 1;
        }
        return ans;
    }
};


// 字典树, ni是words[i]的长度
// 时间复杂度：O(sum(ni))
// 空间复杂度：O(26 * sum(ni))
class Trie{
public:
    unordered_map<char, Trie*> children;
    int depth;
    Trie(int depth){
        this->depth = depth;
    }

    void insert(string &words) {
        Trie* curr = this;
        int n = words.size();
        for (int i = n - 1; i >= 0; i--) {
            if (curr->children.find(words[i]) == curr->children.end()) {
                curr->children[words[i]] = new Trie(curr->depth+1);
            }
            curr = curr->children[words[i]];
        }
    }

    int search() {
        int res = 0;
        if (this->children.size() == 0) return res + this->depth + 1;
        for (auto &[key, child]: this->children) {
            res += child->search();
        }

        return res;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        int res = 0;
        Trie* root = new Trie(0);
        for (int i = 0; i < n; i++) {
            root->insert(words[i]);
        }
        return root->search();
    }
};