

void rotate(int* nums, int numsSize, int k){
    k = k % numsSize;
    for (int i = 0; i < numsSize / 2; i++) {
        int tmp = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 -i] = tmp;
    }
    
    for (int i = 0; i < k / 2; i++) {
        int tmp = nums[i];
        nums[i] = nums[k - 1 - i];
        nums[k - 1 - i] = tmp;
    }
    
    int size = numsSize - k;
    for (int i = 0; i < size / 2; i++) {
        int tmp = nums[i + k];
        nums[i + k] = nums[size - 1 - i + k];
        nums[size - 1 - i + k] = tmp;
    }
}

