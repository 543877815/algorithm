// 前缀和+哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int subarraysDivByK(vector<int> &nums, int k) {
        int n = nums.size();
        int presum = 0, res = 0;
        unordered_map<int, int> record;
        record[0] = 1;
        for (int i = 0; i < n; i++) {
            presum += nums[i];
            if (record.find(presum) != record.end()) {
                res += record[presum];
            }
            record[presum] = presum % k;
        }
        return res;
    }
};