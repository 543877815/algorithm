// 排序+贪心
// 时间复杂度：O(nlgn)
// 空间复杂度：O(lgn)
class Solution {
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end(), [](int a, int b) -> int {
            return abs(a) > abs(b);
        });

        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                res += nums[i];
            } else if (nums[i] <= 0 && k > 0) {
                res += abs(nums[i]);
                k--;
            } else {
                res += nums[i];
            }
        }

        if (k % 2 == 1) {
            res += nums[n - 1] > 0 ? -2 * nums[n - 1] : 2 * nums[n - 1];
        }

        return res;
    }
};