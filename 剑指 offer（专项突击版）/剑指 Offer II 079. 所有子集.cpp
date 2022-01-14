// c++
// 回溯，深度优先搜素
// 时间复杂度：O(n*2^n)
// 空间复杂度：O(n*2^n)
class Solution {
public:
    vector<vector<int>> res;
    void getSubSet(vector<int>& nums, int index, vector<int>& tmp) {
        int n = nums.size();
        res.push_back(tmp);
        for (int i = index; i < n; i++) {
            tmp.push_back(nums[i]);
            getSubSet(nums, i+1, tmp);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        getSubSet(nums, 0, tmp);
        return res;
    }
};