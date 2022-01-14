// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int max_num = 0;
        int second_max_num = -1;
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (max_num <= nums[i]) {
                second_max_num = max_num;
                max_num = nums[i];
                res = i;
            } else {
                second_max_num = max(second_max_num, nums[i]);
            }
        }
        if (max_num >= second_max_num * 2) return res;
        else return -1;
    }
};