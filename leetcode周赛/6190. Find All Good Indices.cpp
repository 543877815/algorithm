// 差分数组
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> goodIndices(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> res;
        vector<int> nonIncrease(n, 0);
        vector<int> nonDecrease(n, 0);
        int presum = 0;
        for (int i = 0; i < n - 1; i++) {
            presum += nums[i + 1] - nums[i] <= 0 ? 1 : 0;
            nonIncrease[i + 1] = presum;
        }
        presum = 0;
        for (int i = 0; i < n - 1; i++) {
            presum += nums[i + 1] - nums[i] >= 0 ? 1 : 0;
            nonDecrease[i + 1] = presum;
        }


        for (int i = k; i < n - k; i++) {
            if (nonIncrease[i - 1] - nonIncrease[i - 1 - (k - 1)] == k - 1 &&
                nonDecrease[i + 1 + k - 1] - nonDecrease[i + 1] == k - 1) {
                res.push_back(i);
            }
        }


        return res;
    }
};