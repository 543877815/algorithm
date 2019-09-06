

bool containsDuplicate(int* nums, int numsSize){
    if (numsSize == 0 || numsSize == 1) return false;
    int min = 2147483647;
    int max = -2147483647;
    for (int i = 0; i < numsSize; i++) {
        if(nums[i] > max) max = nums[i];
        if(nums[i] < min) min = nums[i];
    }
    
    // 哈希表
    int *hash = (int*) malloc(sizeof(int)*(max-min+1));
    for (int i = 0; i < (max-min+1); i++) {
        hash[i] = 0;
    }    
    
    for (int i = 0; i < numsSize; i++) {
        hash[nums[i]-min]++;
        if(hash[nums[i]-min] == 2) return true;
    }
    
    return false;
}

