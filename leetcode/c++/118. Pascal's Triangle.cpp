

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    *returnColumnSizes = (int *)malloc(sizeof(int)*numRows);

    for(int i = 0; i < numRows; i++){
        (*returnColumnSizes)[i] = i + 1;
    }
    
    int **arr = (int **)malloc(sizeof(int*) * numRows);
    for (int i = 0; i < numRows; i++) {
        arr[i] = (int *)malloc(sizeof(int) * (i + 1));
    }
    
    
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j]; 
            }
        }
    }

    return arr;
}

// c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 1; j < i; j++) {
                tmp.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            if (i != 0) tmp.push_back(1);
            res.push_back(tmp);
        }
        return res;
    }
};