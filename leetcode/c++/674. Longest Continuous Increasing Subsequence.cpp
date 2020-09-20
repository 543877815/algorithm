// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int max_num = 1;
        int count = 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                count++;
                max_num = max(max_num, count);
            } else {
                count = 1;
            }
        }
        return max_num;
    }
};