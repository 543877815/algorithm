int max(int x, int y) {
    return x > y ? x : y;
}

int maxSubArray(int* nums, int numsSize){
    int ans = nums[0];
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (sum > 0) {
            sum += nums[i];
        } else {
            sum = nums[i];
        }
        ans = max(ans, sum);
    }
    return ans;
}

