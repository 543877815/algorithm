class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& tmp, vector<bool> &visited) {
        int n = nums.size();
        if (tmp.size() == n) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            if (!visited[i]) {
                visited[i] = true;
                tmp.push_back(nums[i]);
                backtrack(nums, tmp, visited);
                tmp.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return res;
        vector<int> tmp;
        vector<bool> visited = vector<bool>(n, false);
        sort(nums.begin(), nums.end());
        backtrack(nums, tmp, visited);
        sort(nums.begin(), nums.end()); // 先排序
        return res;
    }
};