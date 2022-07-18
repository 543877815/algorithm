// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> numberOfPairs(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, int> hashmap;
        for (int i = 0; i < n; i++) {
            hashmap[nums[i]]++;
        }
        int sum = 0;
        int remain = 0;
        for (auto &[key, value]: hashmap) {
            sum += value / 2;
            remain += value % 2;
        }

        return {sum, remain};
    }
};