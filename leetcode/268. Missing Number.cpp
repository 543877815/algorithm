

int missingNumber(int* nums, int numsSize){
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    int totalVal = 0;
    while(numsSize!=0) {
        totalVal += numsSize;
        numsSize--;
    }
    return totalVal - sum;
}

