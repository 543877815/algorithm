// 回溯
// 时间复杂度：O(2^n*n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& candidates, vector<int>&tmp, int target, int index) {
        int n = candidates.size();
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        if (index >= n || target < 0) return;


        for(int i = index; i < n; i++) {
            if (i > index && candidates[i] == candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            backtrack(candidates, tmp, target-candidates[i], i+1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        if (n == 0) return res;
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        backtrack(candidates, tmp, target, 0);
        return res;
    }
};