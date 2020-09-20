

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void backtrack(char **ans, char *string, int index, int open, int close, int max, int *size) {
    if (index == 2 * max) {
        string[index] = 0;
        char *tmp = (char *)malloc(sizeof(char) * (2 * max + 1));
        strcpy(tmp, string);
        ans[(*size)++] = tmp;
        return;
    }
    
    if (open < max) {
        string[index] = '(';
        backtrack(ans, string, index + 1, open + 1, close, max, size);
    }
    
    if (close < open) {
        string[index] = ')';
        backtrack(ans, string, index + 1, open, close + 1, max, size);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    int num = 1500;
    char **ans = (char **)malloc(sizeof(char*) * num);
    for (int i = 0; i < num; i++) {
        ans[i] = (char *)malloc(sizeof(char) * 2 * n);
    }
    
    char *string = (char *)malloc(sizeof(char) * (2 * n + 1));
    int size = 0;
    backtrack(ans, string, 0, 0, 0, n, &size);
    * returnSize = size;
    return ans;
}

