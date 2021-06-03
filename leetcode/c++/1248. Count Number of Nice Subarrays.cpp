// 前缀和+哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        unordered_map<int, int> record;
        record[0] = 1;
        int res = 0, presum = 0;
        for (int x: nums) {
            presum += x & 1;
            if (record.find(presum - k) != record.end()) {
                res += record[presum - k];
            }
            record[presum]++;
        }
        return res;
    }
};