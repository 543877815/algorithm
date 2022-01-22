// 时间复杂度：O(n)
// 空间复杂度：O(n)
// Fisher-Yates 洗牌算法
class Solution {
public:
    vector<int> nums;

    Solution(vector<int> &nums) {
        this->nums = nums;
    }

    vector<int> reset() {
        return this->nums;
    }

    vector<int> shuffle() {
        vector<int> res = this->nums;
        int n = res.size();
        for (int i = 0; i < n; i++) {
            int index = i + rand() % (n - i);
            int tmp = res[i];
            res[i] = res[index];
            res[index] = tmp;
        }

        return res;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */