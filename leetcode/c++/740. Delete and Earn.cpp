// 动态规划
// 时间复杂度：O(n+m)
// 空间复杂度：O(m)
class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }
        return second;
    }

    int deleteAndEarn(vector<int> &nums) {
        int n = nums.size();
        int maxVal = 0;
        for (int val : nums) {
            maxVal = max(maxVal, val);
        }
        vector<int> sum(maxVal + 1);
        for (int val : nums) {
            sum[val] += val;
        }
        return rob(sum);
    }
};