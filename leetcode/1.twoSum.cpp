#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int min = 2147483647;
    *returnSize = 2;
    int *result = (int*)malloc(sizeof(int) * 2);
    for(int i = 0; i < numsSize; i++){
        if(nums[i] < min){
            min = nums[i];
        }
    }
    int max = target - min;
    int length = max - min + 1;
    // 哈希表长度
    int *hashtable = (int*)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++){
        hashtable[i] = -1;
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i]-min < length) {
            if (hashtable[target-nums[i]-min] != -1) {        //满足相加为target
                result[0] = hashtable[target-nums[i] - min];
                result[1] = i;
                return result;
            }
            hashtable[nums[i]-min] = i;
        }
    }
    free(hashtable);
    

    return result;
}

