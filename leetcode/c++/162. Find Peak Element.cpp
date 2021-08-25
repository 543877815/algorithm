// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) return i;
        }

        return -1;
    }
};

// 二分搜索
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        int left = 0, right = n - 1;
        while (left < right) {
            int middle = (left + right) / 2;
            if (nums[middle] > nums[middle - 1] && nums[middle] > nums[middle + 1]) return middle;
            else if (nums[middle] < nums[middle - 1]) {
                right = middle;
            } else if (nums[middle] < nums[middle + 1]) {
                left = middle;
            }
        }
        return -1;
    }
};