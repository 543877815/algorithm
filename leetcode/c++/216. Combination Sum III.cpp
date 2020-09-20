// 回溯，深度优先搜索
class Solution {
private:
    vector <vector<int>> res;

    void DFS(int k, int n, vector<int> &t, int begin) {
        if (n == 0 && t.size() == k) {
            res.push_back(t);
            return;
        }
        for (int i = begin; i <= 9 && n - i >= 0; i++) {
            if (t.size() <= k) {
                t.push_back(i);
                DFS(k, n - i, t, i + 1);
                t.pop_back();
            } else {
                return;
            }
        }

    }

public:
    vector <vector<int>> combinationSum3(int k, int n) {
        if (k <= 0 || n <= 0 || k > n) return res;
        vector<int> t;
        DFS(k, n, t, 1);
        return res;
    }
};