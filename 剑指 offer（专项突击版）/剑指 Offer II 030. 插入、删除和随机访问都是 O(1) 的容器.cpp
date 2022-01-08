// 哈希表+数组
// 时间复杂度：O(1)
// 空间复杂度：O(1)
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> record;
    unordered_map<int, int> hashmap;

    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hashmap.find(val) == hashmap.end()) {
            hashmap[val] = record.size();
            record.push_back(val);
            return true;
        } else {
            return false;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hashmap.find(val) == hashmap.end()) {
            return false;
        } else {
            record[hashmap[val]] = record.back();
            hashmap[record.back()] = hashmap[val];
            record.pop_back();
            auto iter = hashmap.find(val);
            hashmap.erase(iter);
            return true;
        }

    }

    /** Get a random element from the set. */
    int getRandom() {
        int n = record.size();
        int num = rand() % n;
        return record[num];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */