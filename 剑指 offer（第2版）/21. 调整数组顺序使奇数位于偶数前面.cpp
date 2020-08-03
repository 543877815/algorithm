class Solution {
public:
    vector<int> exchange(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            while (nums[left] % 2 == 1 && left < right) left++;
            while (nums[right] % 2 == 0 && left < right) right--;
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};