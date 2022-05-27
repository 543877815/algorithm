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
     * @param target int整型
     * @return int整型
     */


    int search(vector<int> &nums, int target) {
        // write code here
        int n = nums.size();
        if (n == 0) return -1;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (nums[left] != target) return -1;
        return left;
    }
};