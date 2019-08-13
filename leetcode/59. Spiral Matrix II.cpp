

/**
 * Return an array of arrays of size *returnSize.X
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++){
        (*returnColumnSizes)[i] = n;
    }

    int **arr = (int **) malloc(sizeof(int*) * n);
    if (n == 0) {
        return arr;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(sizeof(int) * n);
    }
    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = n - 1;
    int row = 0;
    int col = 0;
    int flag = 1;
    int count = 1;
    
    for (int i = 0; i < n * n; i++) {
        arr[row][col] = count;
        count++;
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

