// 时间复杂度：O(n)
// 空间复杂度：O(1)
int searchInsert(int *nums, int numsSize, int target) {
    if (target <= nums[0]) return 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (target > nums[i] && target <= nums[i + 1]) {
            return i + 1;
        }
    }
    return numsSize;
}

