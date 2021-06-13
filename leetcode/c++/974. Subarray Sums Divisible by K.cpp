// 哈希表+前缀和
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

            int key = (presum % k + k) % k;  // 防止被除数是负数的情况
            if (record.find(key) != record.end()) {
                res += record[key];
            }

            record[key]++;
        }

        return res;
    }
};