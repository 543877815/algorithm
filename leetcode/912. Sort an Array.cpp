

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    * returnSize = numsSize;
    return nums;
}

