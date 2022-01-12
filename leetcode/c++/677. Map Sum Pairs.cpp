// 说明： c为常数, m表示key-val的数量, n表示字符串key的最大长度

// 暴力扫描
// 时间复杂度：O(nm)
// 空间复杂度：O(n)
class MapSum {
public:
    MapSum() {

    }

    void insert(string key, int val) {
        cnt[key] = val;
    }

    int sum(string prefix) {
        int res = 0;
        for (auto & [key,val] : cnt) {
            if (key.substr(0, prefix.size()) == prefix) {
                res += val;
            }
        }
        return res;
    }
private:
    unordered_map<string, int> cnt;
};

// 前缀哈希映射
// 时间复杂度：O(n^2)
// 空间复杂度：O(nm)
class MapSum {
private:
    unordered_map<string, int> map;
    unordered_map<string, int> prefixmap;

public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        int delta = val;
        if (map.count(key)) {
            delta -= map[key];
        }
        map[key] = val;
        for (int i = 1; i <= key.size(); i++) {
            prefixmap[key.substr(0, i)] += delta;
        }
    }

    int sum(string prefix) {
        return prefixmap[prefix];
    }
};


// 字典树
// 时间复杂度：O(n)
// 空间复杂度：O(cnm)
class Trie{
public:
    unordered_map<char, Trie*> children;
    int val = 0;
    Trie(){}

    void insert(string& key, int val) {
        Trie* curr = this;
        int n = key.size();
        for (int i = 0; i < n; i++) {
            if (curr->children.find(key[i]) == curr->children.end()) {
                curr->children[key[i]] = new Trie();
            }
            curr = curr->children[key[i]];
        }
        curr->val = val;
    }

    int sum(string& prefix, int index) {
        int n = prefix.size();
        int res = 0;
        if (index < n) {
            if (this->children.find(prefix[index]) != this->children.end()) {
                res += this->children[prefix[index]]->sum(prefix, index+1);
            } else return 0;
        } else {
            res += this->val;
            for (auto &[key, child]: this->children) {
                res += child->sum(prefix, index);
            }
        }
        return res;
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    Trie* root;
    MapSum() {
        root = new Trie();
    }

    void insert(string key, int val) {
        root->insert(key, val);
    }

    int sum(string prefix) {
        return root->sum(prefix, 0);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */