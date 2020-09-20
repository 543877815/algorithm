

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int maxNum = 0;
    int count = 0;
    for(int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) count++;
        else count = 0;
        if (count > maxNum) maxNum = count;
    }
    return maxNum;
}

