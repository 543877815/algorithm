

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


// c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int num = 1, i = 0, j = 0;
        int up = 0, down = n - 1, left = 0, right = n - 1;
        bool UP = false, DOWN = false, LEFT = false, RIGHT = true;
        while (num <= n * n) {
            if (RIGHT) {
                res[i][j] = num;
                if (j == right) {RIGHT = false; DOWN = true; up++; i++;}
                else j++;
            } else if (DOWN) {
                res[i][j] = num;
                if (i == down) {DOWN = false; LEFT = true; right--; j--;}
                else i++;
            } else if (LEFT) {
                res[i][j] = num;
                if (j == left) {LEFT = false; UP = true; down--; i--;}
                else j--;
            } else if (UP) {
                res[i][j] = num;
                if (i == up) {UP = false; RIGHT = true; left++; j++;}
                else i--;
            }
            num ++;
        }
        return res;
    }
};