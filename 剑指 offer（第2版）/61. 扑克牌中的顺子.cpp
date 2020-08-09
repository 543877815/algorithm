// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    bool isStraight(vector<int> &nums) {
        int n = nums.size();
        if (n < 5) return false;
        sort(nums.begin(), nums.end());
        int numberOfZero = 0;
        int numberOfGap = 0;

        // 统计0的个数
        for (int i = 0; i < n; i++)
            if (nums[i] == 0) numberOfZero++;
            else break;

        // 统计数组中的间隔数目
        int small = numberOfZero;
        int big = small + 1;
        while (big < n) {
            // 两个数相等，有对子，不可能是顺子
            if (nums[small] == nums[big]) return false;
            numberOfGap += nums[big] - nums[small] - 1;
            small = big++;
        }

        return numberOfGap <= numberOfZero;
    }
};