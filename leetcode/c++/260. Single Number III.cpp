

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    
    // 先异或一次
    int acc = 0;
    for (int i = 0; i < numsSize; i++) {
        acc ^= nums[i];
    }
    // 取非0位
    acc &= (~acc) + 1;
    // 取最高非0位进行异或
    int a = 0, b = 0;
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] & acc) == acc) a ^= nums[i];
        else b ^= nums[i];
    } 
    
    int *ans = (int *)malloc(sizeof(int)*2);
    ans[0] = a;
    ans[1] = b;
    *returnSize = 2;
    return ans;
}

