// 哈希表映射
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int findLHS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        map<int, int> hash;
        int pre_key = INT_MAX;
        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;
            pre_key = min(pre_key, nums[i]);
        }
        int pre_value = 0;
        int res = 0;
        for (auto i : hash) {
            if (i.first - pre_key == 1) {
                res = max(res, i.second + pre_value);
            }
            pre_key = i.first;
            pre_value = i.second;
        }
        return res;
    }
};