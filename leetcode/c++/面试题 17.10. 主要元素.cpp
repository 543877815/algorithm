// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, int> record;
        for (int i = 0; i < n; i++) {
            record[nums[i]]++;
        }


        int res = -1;
        for (auto &[key, value]: record) {
            if (value > n / 2) res = key;
        }

        return res;
    }
};


// 摩尔投票法
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();
        int count = 0;
        int candidate = -1;
        for (int i = 0; i < n; i++) {
            if (count == 0) candidate = nums[i];
            if (candidate == nums[i]) count++;
            else count--;
        }

        count = 0;
        for (int i = 0; i < n; i++) {
            if (candidate == nums[i]) count++;
        }
        return count > n / 2 ? candidate : -1;
    }
};