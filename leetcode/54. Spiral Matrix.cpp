

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int *arr;
    if (matrixSize == 0) {
        *returnSize = 0;
        return arr;
    }
    int left = 0;
    int right = (*matrixColSize) - 1;
    int top = 0;
    int bottom = matrixSize - 1;
    int row = 0;
    int col = 0;
    int flag = 1;
    *returnSize = matrixSize * (*matrixColSize);
    arr = (int *) malloc(sizeof(int)*(*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        arr[i] = matrix[row][col];
        if (flag == 1 && col < right) {
            col++;
            continue;
        } else if(flag == 2 && row < bottom) {
            row++;
            continue;
        } else if(flag == 3 && col > left) {
            col--;
            continue;
        } else if(flag == 4 && row > top) {
            row--;
            continue;
        }
        if (flag == 1 && col == right) {
            top = top + 1;
            row = top;
            flag = 2;
        } else if (flag == 2 && row == bottom) {
            right = right - 1;
            col = right;
            flag = 3;
        } else if (flag == 3 && col == left) {
            bottom = bottom - 1;
            row = bottom;
            flag = 4;
        } else if (flag == 4 && row == top) {
            left = left + 1;
            col = left;
            flag = 1;
        }
    } 
    return arr;
}

