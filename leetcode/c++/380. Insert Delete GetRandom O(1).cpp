// 时间复杂度：O(1)
// 空间复杂度：O(1)
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> nums;
    unordered_map<int, int> record;

    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (record.count(val)) return false;
        else {
            record[val] = nums.size();
            nums.push_back(val);
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (record.find(val) != record.end()) {
            record[nums.back()] = record[val];
            swap(nums[record[val]], nums.back());
            record.erase(val);
            nums.pop_back();
            return true;
        } else {
            return false;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};