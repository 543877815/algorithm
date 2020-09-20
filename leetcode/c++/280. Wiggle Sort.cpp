void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void wiggleSort(int* nums, int numsSize){
    for (int i = 0; i < numsSize - 1; i++) {
        if ((i % 2 == 0) == (nums[i] > nums[i+1])) {
            swap(&nums[i], &nums[i+1]);
        }
    }
}

