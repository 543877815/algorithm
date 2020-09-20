

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
    
    int **arr = (int **)malloc(sizeof(int*) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        arr[i] = (int *)malloc(sizeof(int) * (i + 1));
    }
    
    for (int i = 0; i < *returnSize; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j]; 
            }
        }
    }
    // for (int i = 0; i < *returnSize; i++) {
    //     for (int j = 0; j < i + 1; j++) {
    //         printf("%d ", arr[i][j]);  
    //     }
    //     printf("\n");
    // }
    return arr[rowIndex];
}

