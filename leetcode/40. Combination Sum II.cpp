// 回溯，深度优先搜索
// 时间复杂度：O(n^n)
// 空间复杂度：O(target)
class Solution {
private:
    vector <vector<int>> res;
    vector<bool> used;

    void DFS(vector<int> &candidates, int target, int begin, vector<int> &t) {
        if (target == 0) {
            res.push_back(t);
            return;
        }
        for (int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && !used[i - 1]) continue;
            t.push_back(candidates[i]);
            used[i] = true;
            DFS(candidates, target - candidates[i], i + 1, t);
            used[i] = false;
            t.pop_back();
        }
    }

public:
    vector <vector<int>> combinationSum2(vector<int> &candidates, int target) {
        if (candidates.empty()) return res;
        sort(candidates.begin(), candidates.end());
        vector<int> t;
        used = vector<bool>(candidates.size(), false);
        DFS(candidates, target, 0, t);
        return res;
    }
};