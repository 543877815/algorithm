// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (target == nums[i]) return i;
        }
        return -1;
    }
};


// 二分查找
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (nums[middle] == target) return middle;
            else if (nums[middle] < nums[right]) {   // 右半段有序
                if (nums[middle] < target && target <= nums[right]) left = middle + 1;
                else right = middle - 1;
            } else {
                if (nums[left] <= target && target < nums[middle]) right = middle - 1;
                else left = middle + 1;
            }
        }
        return -1;
    }
};