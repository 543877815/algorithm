// 回溯
// 时间复杂度：O(2^n)
// 空间复杂度：O(n)
class Solution {
public:
    vector <vector<int>> res;

    void backtrack(vector<int> &num, vector<int> &tmp, vector<bool> used, int index, int target) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        int n = num.size();
        for (int i = index; i < n; i++) {
            if (target < num[i]) return;
            if (i > 0 && num[i] == num[i - 1] && !used[i - 1]) continue;
            tmp.push_back(num[i]);
            used[i] = true;
            backtrack(num, tmp, used, i + 1, target - num[i]);
            tmp.pop_back();
            used[i] = false;
        }
    }

    vector <vector<int>> combinationSum2(vector<int> &num, int target) {
        vector<int> tmp;
        int n = num.size();
        vector<bool> used(n, false);
        sort(num.begin(), num.end());
        backtrack(num, tmp, used, 0, target);

        return res;
    }
};