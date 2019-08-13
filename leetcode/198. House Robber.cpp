int max(int a, int b) {
    return a > b ? a : b;
}

int rob(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    int *F = (int *) malloc(sizeof(int) * numsSize);
    F[0] = nums[0];
    F[1] = max(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        F[i] = max(F[i-1], F[i-2] + nums[i]);
    }
    return F[numsSize-1];
}

