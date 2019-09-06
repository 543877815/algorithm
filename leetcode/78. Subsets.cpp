

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int size = (int)pow(2, numsSize);
    int **ans = (int **)malloc(sizeof(int*)*size);
    for (int i = 0; i < size; i++) {
        ans[i] = (int *)malloc(sizeof(int)*numsSize);
    }
    
    *returnSize = size;
    *returnColumnSizes = (int*)malloc(sizeof(int)*size);
    for (int i = 0; i < (1 << numsSize); i ++) {
        int index = 0;
        for (int j = 0; j < numsSize; j++) {
            if (((i >> j) & 1) == 1) ans[i][index++] = nums[j];
        }
        (*returnColumnSizes)[i] = index;
    }
    
    return ans;
}

