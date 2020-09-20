class Solution {
private:
    vector<vector<int>> res;
    void DFS(vector<int> &nums, vector<int> &t, int begin) {
        if (begin > nums.size()) return;
        res.push_back(t);
        for (int i = begin; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1] && begin != i) continue;
            t.push_back(nums[i]);
            DFS(nums, t, i + 1);
            t.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return res;
        vector<int> t;
        sort(nums.begin(), nums.end());
        DFS(nums, t, 0);
        return res;
    }
};