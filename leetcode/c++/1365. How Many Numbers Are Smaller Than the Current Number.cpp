// 时间复杂度：O(n+nlgn)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector<int> res(nums);
        sort(res.begin(), res.end(), less<int>());
        unordered_map<int, int> hash;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (hash.count(res[i]) == 0)
                hash[res[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            res[i] = hash[nums[i]];
        }
        return res;
    }
};