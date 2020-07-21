class Solution {
public:
    int search(vector<int> &nums, int target) {
        int res = 0;
        int left = 0;
        int right = nums.size() - 1;
        int middle = (left + right) / 2;
        while (left <= right) {
            if (nums[middle] > target) {
                right = middle - 1;
                middle = (left + right) / 2;
            } else if (nums[middle] < target) {
                left = middle + 1;
                middle = (left + right) / 2;
            } else {
                int tmp = middle + 1;
                while (middle >= 0 && target == nums[middle]) {
                    middle--;
                    res++;
                };
                while (tmp < nums.size() && target == nums[tmp]) {
                    tmp++;
                    res++;
                }
                break;
            }
        }
        return res;
    }
};