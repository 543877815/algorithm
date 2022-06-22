// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxAscendingSum(vector<int> &nums) {
        int sum = 0;
        int res = 0;
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        for (int i = 0; i < n - 1; i++) {
            sum += nums[i];
            res = max(res, sum);
            if (nums[i] >= nums[i + 1]) {
                sum = 0;
            }
        }

        if (nums[n - 1] > nums[n - 2]) {
            sum += nums[n - 1];
            res = max(res, sum);
        }
        return res;

    }
};