

int removeDuplicates(int* nums, int numsSize){
    for (int i = 1; i < numsSize; i++) {
        if(nums[i] == nums[i-1]) {
            for (int j = i; j < numsSize - 1; j++) {
                nums[j] = nums[j+1]; 
            }
            i--;
            numsSize--;
        }
    }
    return numsSize;
}

