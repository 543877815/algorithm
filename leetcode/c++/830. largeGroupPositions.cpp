

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char * S, int* returnSize, int** returnColumnSizes){
    char first;
    int startindex = -1;
    int endindex = -1;
    int i=0;
    *returnSize = 0;
    int k = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) *1000);
    int **returnArray = (int **)malloc(sizeof(int*)*1000);
    while(*S){
        printf("%c ", *S);
        first = *S;
        startindex = i;
        int length = 1;
        while(*++S && first == *S){
            length++;
        }
        if(length >= 3){
            endindex = startindex + length - 1;
            (*returnColumnSizes)[(*returnSize)] = 2;
            returnArray[(*returnSize)] = (int *)malloc(sizeof(int)*2);
            returnArray[(*returnSize)][0] = startindex;
            returnArray[(*returnSize)][1] = endindex;
            k++;
            (*returnSize)++;
        }
        i += length;
        printf("\n");
    }
    return returnArray;
}


// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int n = s.size();
        int last = -1;
        for (int i = 0; i < n; i++){
            if (i < n - 1) {
                if (s[i] == s[i+1]) {
                 if (last == -1) last = i;
                } else {
                    if (last != -1 && i - last >= 2) {
                        res.push_back({last, i});
                    }
                    last = -1;
                }
            } else {
                if (last != -1 && i - last >= 2) {
                    res.push_back({last, i});
                }
            }
        }
        return res;
    }
};