

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int f(int a, int b, int c, int x){
    return a * x * x + b * x + c;
}

float my_abs(float x) {
    return x > 0 ? x : -x;
}

int* sortTransformedArray(int* nums, int numsSize, int a, int b, int c, int* returnSize){
    int *arr = (int *) malloc(sizeof(int) * numsSize); // 分配数组
    if (a!=0) {
        float ab = (float) - b / (2*a);
        int left = 0, right = numsSize - 1; // 双指针
        
        if (a > 0) {
            int size = numsSize - 1;
            while(left <= right){
                if (my_abs((float)nums[left] - ab) > my_abs((float)nums[right] - ab)) {
                    int x = nums[left++];
                    arr[size--] = f(a,b,c,x);
                } else {
                    int x = nums[right--];
                    arr[size--] = f(a,b,c,x);
                }
            }
        } else {
            int size = 0;
            while(left <= right){
                printf("%d %d\n", nums[left] - ab, nums[right] - ab);
                if (my_abs((float)nums[left] - ab) > my_abs((float)nums[right] - ab)) {
                    int x = nums[left++];
                    arr[size++] = f(a,b,c,x);
                } else {
                    int x = nums[right--];
                    arr[size++] = f(a,b,c,x);
                }
            }
        }
    } else {
        if (b==0) {
            for (int i = 0; i < numsSize; i++) {
                arr[i] = c;
            }
        } else if (b > 0) { // 升序
            for (int i = 0; i < numsSize; i++) {
                arr[i] = nums[i] * b + c;
            }
        } else {
            for (int i = 0; i < numsSize; i++) {
                arr[i] = nums[numsSize - 1 - i] * b + c;
            }
        }
    }
    
    * returnSize = numsSize;
    return arr;
}

