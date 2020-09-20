// c++ 回溯
// 时间复杂度：O(logn + n!)
// 空间复杂度：O(n)
class Solution {
private:
    vector <vector<int>> res;
    vector<bool> used;

    // p中保存了一个有index个元素的排列
    // 向这个排列的末尾添加第index+1个元素，获得一个有index+1个元素的排列
    void generatePermutation(const vector<int> &nums, int index, vector<int> &p) {
        if (index == nums.size()) {
            res.push_back(p);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // 剪枝条件：i > 0 是为了保证 nums[i - 1] 有意义
            // 写 !used[i - 1] 是因为 nums[i - 1] 在深度优先遍历的过程中刚刚被撤销选择
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            if (!used[i]) {
                p.push_back(nums[i]);
                used[i] = true;
                generatePermutation(nums, index + 1, p);
                used[i] = false;
                p.pop_back();
            }
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        if (nums.size() == 0) return res;
        sort(nums.begin(), nums.end()); // 先排序
        used = vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermutation(nums, 0, p);
        return res;
    }
};