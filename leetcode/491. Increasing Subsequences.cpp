// DFS
// 时间复杂度：O(2^n*n)
// 空间复杂度：O(n)
class Solution {
private:
    vector <vector<int>> res;
    vector<bool> visited;

    bool checkRepeat(vector<int> &nums, int begin, int end) {
        for (int i = end - 1; i >= begin; i--) {
            if (nums[i] == nums[end] && !visited[i]) return true;
        }
        return false;
    }

    void DFS(vector<int> &nums, vector<int> &sq, int index) {
        for (int i = index; i < nums.size(); i++) {
            if (i > 0 && checkRepeat(nums, index, i)) continue;
            if (sq.empty() || (nums[i] >= sq.back())) {
                visited[i] = true;
                sq.push_back(nums[i]);
                if (sq.size() >= 2) res.push_back(sq);
                DFS(nums, sq, i + 1);
                sq.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    vector <vector<int>> findSubsequences(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return res;
        visited = vector<bool>(n, false);
        vector<int> sq;
        DFS(nums, sq, 0);
        return res;
    }
};