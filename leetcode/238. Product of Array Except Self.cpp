// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return nums;

        vector<int> res(n, 1);
        for (int i = 0, product = 1; i < nums.size(); product *= nums[i], i++) {
            res[i] *= product;
        }

        for (int i = n - 1, product = 1; i >= 0; product *= nums[i], i--) {
            res[i] *= product;
        }

        return res;
    }
};