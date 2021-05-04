// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) return true;
        }
        return false;
    }
};

// 二分查找
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            // 处理重复数字
            while (left < right && nums[left] == nums[left + 1]) left++;
            while (left < right && nums[right] == nums[right - 1]) right--;
            int middle = (left + right) / 2;
            if (nums[middle] == target) return true;
            else if (nums[middle] < nums[right]) {
                if (nums[middle] < target && target <= nums[right]) left = middle + 1;
                else right = middle - 1;
            } else {
                if (nums[left] <= target && target < nums[middle]) right = middle - 1;
                else left = middle + 1;
            }
        }

        return false;
    }
};