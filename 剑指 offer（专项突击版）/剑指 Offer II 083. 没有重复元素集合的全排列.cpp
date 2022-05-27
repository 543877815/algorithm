// 回溯
// 时间复杂度：O(2^n * n)
// 空间复杂的：O(n)
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
            if (!visited[i]) {
                visited[i] = true;
                tmp.push_back(nums[i]);
                backtrack(nums, tmp, visited);
                tmp.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return res;
        vector<int> tmp;
        vector<bool> visited = vector<bool>(n, false);
        backtrack(nums, tmp, visited);

        return res;
    }
};