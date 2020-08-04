// 回溯
class Solution {
private:
    vector <vector<int>> res;

    void DFS(vector<int> &candidates, int target, vector<int> t, int begin) {
        for (int i = begin; i < candidates.size(); i++) {
            if (candidates[i] > target) return;
            t.push_back(candidates[i]);
            if (candidates[i] == target) {
                res.push_back(t);
                return;
            }
            DFS(candidates, target - candidates[i], t, i);
            t.pop_back();
        }
    }

public:
    vector <vector<int>> combinationSum(vector<int> &candidates, int target) {
        if (candidates.empty()) return res;
        sort(candidates.begin(), candidates.end());
        vector<int> t;
        DFS(candidates, target, t, 0);
        return res;
    }
};

// 传引用优化
class Solution {
private:
    vector <vector<int>> res;

    void DFS(vector<int> &candidates, int target, vector<int> &t, int begin) {
        if (target == 0) {
            res.push_back(t);
            return;
        }
        for (int i = begin; i < candidates.size() && target - candidates[i] >= 0; i++) {
            t.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], t, i);
            t.pop_back();
        }
    }

public:
    vector <vector<int>> combinationSum(vector<int> &candidates, int target) {
        if (candidates.empty()) return res;
        sort(candidates.begin(), candidates.end());
        vector<int> t;
        DFS(candidates, target, t, 0);
        return res;
    }
};