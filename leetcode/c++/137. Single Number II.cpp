

int singleNumber(int* nums, int numsSize){
    int b1 = 0; // 出现一次的位
    int b2 = 0; // 出现两次的位
    for (int i = 0; i < numsSize; i++) {
        b1 = (b1 ^ nums[i]) & ~ b2; // 既不在出现一次的b1，也不在出现两次的b2里面，我们就记录下来，出现了一次，再次出现则会抵消
        b2 = (b2 ^ nums[i]) & ~ b1; // 既不在出现两次的b2里面，也不再出现一次的b1里面(不止一次了)，记录出现两次，第三次则会抵消
    }
    return b1;
}

