


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), cmp);
    
    int number = (numsSize * (numsSize-1) * (numsSize-2)) / 6;
    int **ans = (int **) malloc (sizeof(int*) * number);
    for (int i = 0; i < number; i++) {
        ans[i] = (int *)malloc(sizeof(int) * 4);
    }
    int index = 0;
    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < numsSize - 2; j++) {
            int left = j + 1;
            int right = numsSize - 1;
            if (j > 1 && j - 1 != i && nums[j] == nums[j - 1]) continue;
            while(left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    ans[index][0] = nums[i];
                    ans[index][1] = nums[j];
                    ans[index][2] = nums[left++];
                    ans[index][3] = nums[right--];
                    while(left < numsSize && nums[left]==nums[left-1]) left++;
                    while(right > 0 && nums[right]==nums[right+1]) right--;
                    index ++;
                } else if (sum - target > 0) {
                    right --;
                } else if (sum - target < 0) {
                    left ++;
                }
            }
        }
    }
    
    *returnColumnSizes = (int *)malloc(sizeof(int)*index);
    for(int i = 0; i < index; i++){
        (*returnColumnSizes)[i] = 4;
    }
    
    *returnSize = index;
    return ans;
}

