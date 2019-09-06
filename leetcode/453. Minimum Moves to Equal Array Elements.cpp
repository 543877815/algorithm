


int minMoves(int* nums, int numsSize){
    int min = 2147483647; 
    for (int i = 0; i < numsSize; i++) {
        if (min > nums[i]) min = nums[i];
    }
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        ans += nums[i] - min;
    }
    return ans;
}

