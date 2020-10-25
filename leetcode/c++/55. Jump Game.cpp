// 贪心算法
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return true;
        int maxn = 0;
        int pre = 0;
        for (int i = 0; i < n; i++) {
            maxn = max(maxn, nums[i] + i);
            if (maxn == i && i != n - 1) return false;
        }
        return maxn >= n - 1;
    }
};