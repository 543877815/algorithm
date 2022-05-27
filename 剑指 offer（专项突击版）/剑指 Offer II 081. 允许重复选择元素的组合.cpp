// 回溯
// 时间复杂度：O(2^n*n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& candidates, vector<int> tmp, int target, int index) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        int n = candidates.size();
        if (target < 0 || index > n) return;
        for (int i = index; i < n; i++) {

            tmp.push_back(candidates[i]);
            backtrack(candidates, tmp, target - candidates[i], i);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, tmp, target, 0);

        return res;
    }
};