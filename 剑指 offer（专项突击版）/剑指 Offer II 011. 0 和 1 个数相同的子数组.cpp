// 哈希表+前缀和
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) nums[i] = -1;
        }
        unordered_map<int, int> record;
        record[0] = -1;
        int presum = 0;
        for (int i = 0; i < n; i++) {
            presum += nums[i];
            if (record.find(presum) != record.end()) {
                res = max(res, i - record[presum]);
            } else {
                record[presum] = i;
            }
        }

        return res;
    }
};