int max(int a, int b, int c){
    if (a > b) {
        if (a > c) return a;
        else return c;
    } else {
        if (b > c) return b;
        else return c;
    }
}

int min(int a, int b, int c){
    if (a < b) {
        if (a < c) return a;
        else return c;
    } else {
        if (b < c) return b;
        else return c;
    }
}

int middle(int a, int b, int c) {
    if (b > a && a > c || c > a && a > b) return a;
    if (a > b && b > c || c > b && b > a) return b;
    if (a > c && c > b || b > c && c > a) return c;
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numMovesStones(int a, int b, int c, int* returnSize){
    int minimum_moves = 0;
    
    int max_N = max(a, b, c);
    int middle_N = middle(a, b, c);
    int min_N = min(a, b, c);
    
    int high_dis = max_N - middle_N;
    int low_dis = middle_N - min_N;
    
    if (high_dis > 2 && low_dis > 2) {
        minimum_moves = 2;
    } else if(high_dis > 1 || low_dis > 1){
        minimum_moves = 1;
    } else {
        minimum_moves = 0;
    }
    
    int maximum_moves = max(a,b,c) - min(a,b,c) - 2;
    *returnSize = 2;
    int *ans = (int *) malloc(sizeof(int) * 2);
    ans[0] = minimum_moves;
    ans[1] = maximum_moves;
    return ans;
}

