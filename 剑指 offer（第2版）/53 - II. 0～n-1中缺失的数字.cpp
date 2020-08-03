// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        if (nums[0] == 1) return 0;
        int left = 0;
        int right = nums.size() - 1;
        int middle = (left + right) / 2;
        while (left <= right) {
            if (nums[middle] == middle) {
                left = middle + 1;
                middle = (left + right) / 2;
            } else {
                right = middle - 1;
                middle = (left + right) / 2;
            }
        }
        if (middle==nums.size()-1) return nums.size();
        return middle+1;
    }
};