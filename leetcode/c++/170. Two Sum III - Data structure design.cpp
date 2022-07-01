// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class TwoSum {
private:
    vector<int> nums;
    bool isSorted = false;
public:
    TwoSum() {

    }

    void add(int number) {
        nums.push_back(number);
        isSorted = false;
    }

    bool find(int value) {
        if (!isSorted) {
            isSorted = true;
            sort(nums.begin(), nums.end());
        }

        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == value) return true;
            else if (sum > value) {
                right--;
            } else {
                left++;
            }
        }

        return false;

    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */

// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class TwoSum {
public:
    unordered_map<long long, int> mymap;

    TwoSum() {

    }

    void add(int number) {
        mymap[number]++;
    }

    bool find(int value) {
        for (auto &[key, val]: mymap) {
            int remain = value - key;
            if (mymap.find(remain) != mymap.end()) {
                if (remain == key) {
                    if (val > 1) return true;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */