// 面向用例编程
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int findPeakElement(vector<int> &nums) {
        // write code here
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return 0;
        if (n == 2) {
            return nums[0] > nums[1] ? 0 : 1;
        }
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        if (nums[1] < nums[0]) return 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
        }
        return -1;
    }
};

// 二分查找
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int findPeakElement(vector<int> &nums) {
        // write code here
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) right = mid;
            else left = mid + 1;
        }

        return right;
    }
};