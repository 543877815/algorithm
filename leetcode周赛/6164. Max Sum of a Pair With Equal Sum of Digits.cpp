// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> hashmap;
        for (int i = 0; i < n; i++) {
            int tmp = nums[i];
            int sum = 0;
            while (tmp != 0) {
                sum += tmp % 10;
                tmp /= 10;
            }
            hashmap[sum].push_back(nums[i]);
        }

        int res = -1;
        for (auto &[key, value]: hashmap) {
            int n = value.size();
            if (n == 1) continue;
            sort(value.begin(), value.end());
            res = max(res, value[n-1] +value[n-2]);
        }
        return res;
    }
};