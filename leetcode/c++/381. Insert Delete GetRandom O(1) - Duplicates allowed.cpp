// 时间复杂度: O(1)
// 空间复杂度：O(n)
class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> idx;  // idx记录着索引
    vector<int> nums;  // nums记录着值

    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        idx[val].insert(nums.size() - 1);
        return idx[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (idx.find(val) == idx.end()) return false;
        // 找到val的第一值的索引
        int i = *(idx[val].begin());  // begin 返回的是迭代器
        // 删除nums[i]等于交换最后一个元素再删除最后一个元素
        nums[i] = nums.back();
        // 维护val的索引
        idx[val].erase(i);
        // 维护num.back()的索引
        idx[nums[i]].erase(nums.size() - 1);
        if (i < nums.size() - 1) idx[nums[i]].insert(i);
        // 维护val的索引
        if (idx[val].size() == 0) idx.erase(val);
        // 删除nums最后一项
        nums.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */