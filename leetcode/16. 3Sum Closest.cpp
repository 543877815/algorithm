int abs(int x) {
    return x > 0 ? x : -x;
}

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), cmp);
    int minDis = 99999;
    int sum = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        while(left != right) {
            if (minDis > abs(nums[i] + nums[left] + nums[right] - target)) {
                minDis = abs(nums[i] + nums[left] + nums[right] - target);
                sum = nums[i] + nums[left] + nums[right];
            }
                
            if (nums[i] + nums[left] + nums[right] > target) {
                right --;
            } else {
                left ++;
            }
        }
    }
    return sum;
}
