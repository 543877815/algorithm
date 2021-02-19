// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        unordered_map<int, vector<int>> record;  // begin, end, count
        int res = n, degree = 1;
        for (int i = 0; i < n; i++) {
            if (record.count(nums[i]) == 0) {
                record[nums[i]] = {i, i, 1};
            } else {
                record[nums[i]][1] = i;
                record[nums[i]][2]++;
                degree = max(degree, record[nums[i]][2]);
            }
        }

        for (auto &[key, value]: record) {
            if (degree == value[2]) {
                res = min(res, value[1] - value[0] + 1);
            }
        }
        return res;
    }
};