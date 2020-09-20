

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    if (digitsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int *arr = (int *) malloc(sizeof(int) * (digitsSize+1));
    int carry = 1;
    int i ;
    for (i = 0; i < digitsSize; i++) {
        int tmp = carry + digits[digitsSize - 1 - i];
        carry = tmp / 10;
        arr[i] = tmp % 10;
    }
    if (carry == 1) {
        arr[i] = carry;
        i++;
    }
    for (int j = 0; j < i / 2; j++) {
        int tmp = arr[j];
        arr[j] = arr[i-j-1];
        arr[i-j-1] = tmp;
    }
    * returnSize = i;
    return arr;
}

