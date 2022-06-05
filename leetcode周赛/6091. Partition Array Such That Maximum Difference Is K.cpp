// 排序+贪心
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return 1;
        sort(nums.begin(), nums.end());
        int last = nums[0];
        int res = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] - last > k) {
                last = nums[i];
                res++;
            }
        }
        return res;
    }
};