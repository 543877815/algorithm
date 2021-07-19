// 排序+贪心
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    int minPairSum(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxn = 0;
        for (int i = 0; i < n / 2; i++) {
            maxn = max(maxn, nums[i] + nums[n - i - 1]);
        }

        return maxn;
    }
};