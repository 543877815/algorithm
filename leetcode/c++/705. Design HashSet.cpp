// 时间复杂度：O(n)
// 空间复杂度：O(n)
class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<bool> hashMap = vector<bool>(1000001, false);

    MyHashSet() {

    }

    void add(int key) {
        hashMap[key] = true;
    }

    void remove(int key) {
        hashMap[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hashMap[key] == true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

// 时间复杂度：O(n/b)
// 空间复杂度：O(n+b)
class MyHashSet {
public:
    vector <list<int>> data;
    static const int base = 769;

    static int hash(int key) {  // 取余
        return key & base;
    }

    /** Initialize your data structure here. */
    MyHashSet() : data(base) {}

    void add(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) return;
        }
        data[h].push_back(key);
    }

    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) {
                data[h].erase(it);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */