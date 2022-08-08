// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        unordered_map<int, int> hashmap;
        for (int i = 0; i < n; i++) {
            hashmap[nums[i]]++;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (hashmap.count(nums[i] + diff) && hashmap.count(nums[i] + diff + diff)) {
                res ++;
            }
        }

        return res;
    }
};