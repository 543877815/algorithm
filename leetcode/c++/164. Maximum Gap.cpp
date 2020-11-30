// 快速排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    int maximumGap(vector<int> &nums) {
        int m = nums.size();
        if (m < 2) return 0;
        sort(nums.begin(), nums.end());
        int max_num = INT_MIN;
        for (int i = 0; i < m - 1; i++) {
            if (nums[i + 1] - nums[i] > max_num) {
                max_num = nums[i + 1] - nums[i];
            }
        }

        return max_num;
    }
};


///