// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector <string> summaryRanges(vector<int> &nums) {
        int n = nums.size();
        vector <string> res;
        if (n == 0) return res;
        int last = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1] - 1) {
                if (i == last) res.push_back(to_string(nums[i]));
                else res.push_back(to_string(nums[last]) + "->" + to_string(nums[i]));
                last = i + 1;
            }
        }
        if (nums[last] != nums[n - 1]) res.push_back(to_string(nums[last]) + "->" + to_string(nums[n - 1]));
        else res.push_back(to_string(nums[n - 1]));
        return res;
    }
};