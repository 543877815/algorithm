// 超时了

int hammingWeight(uint32_t n) {
    int num = 0;
    for(int i = 0; i < 32; i++) {
        num += n & 1;
        n = n >> 1;
    }
    return num;
}

int hammingDistance(int x, int y){
    int tmp = x ^ y;
    return hammingWeight(tmp);
}


int totalHammingDistance(int* nums, int numsSize){
    printf("%d", numsSize);
    int ans = 0;
    for(int i = 0; i < numsSize; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            ans += hammingDistance(nums[i], nums[j]);
        }
    }
    return ans;
}

// 位运算


int totalHammingDistance(int* nums, int numsSize){
    // 初始化计数器
    int *counter = (int*)malloc(sizeof(int)*32);
    for (int i = 0; i < 32; i++) {
        counter[i] = 0;
    }
    // 计算i的个数
    for(int i = 0; i < numsSize; i++) {
        for (int j = 0; j < 32; j++) {
            counter[j] += nums[i] & 1;
            nums[i] = nums[i] >> 1;
            if (nums[i] == 0) break;
        }
    }
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        ans += counter[i] * (numsSize - counter[i]);
    }
    return ans;
}

