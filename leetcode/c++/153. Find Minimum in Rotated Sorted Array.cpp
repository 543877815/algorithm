// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = min(res, nums[i]);
        }
        return res;
    }
};

// 二分查找
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
// 算法：
// 4 5 6 7 2 3
// l   m     r
// 4 5 6 7 2 3
//       l m r
// 4 5 6 7 2 3
//         l r
// 4 5 6 7 2 3
//         lr
// 1.找到数组的中间元素 mid。
// 2.如果中间元素 > 数组第一个元素，我们需要在 mid 右边搜索变化点。
// 3.如果中间元素 < 数组第一个元素，我们需要在 mid 左边搜索变化点。
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int middle = (left + right) / 2;
            if (nums[middle] < nums[right]) right = middle;
            else left = middle + 1;
        }
        return nums[left];
    }
};