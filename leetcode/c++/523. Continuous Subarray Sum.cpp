// 前缀和+哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long presum = 0;
        unordered_map<int, int> record;
        record[0] = -1;
        for (int i = 0; i < n; i++) {
            presum += nums[i];
            long long index = (presum % k + k) % k;
            if (record.find(index) != record.end()) {
                if (i - record[index] >= 2)
                    return true;
            } else {
                record[index] = i;
            }
        }
        return false;
    }
};