#define INF 1000

int min(int a, int b, int c) {
    if(a <= b && a <= c) return a;
    if(b <= a && b <= c) return b;
    if(c <= b && c <= a) return c;
    return -1;
}

int minCost(int** costs, int costsSize, int* costsColSize){
    if (costsSize == 0) return 0;
    int **dp = (int **) malloc(sizeof(int*)*costsSize);
    for (int i = 0; i < costsSize; i++) {
        dp[i] = (int *) malloc(sizeof(int)*((*costsColSize) + 1));
    }
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];
    dp[0][3] = min(costs[0][0], costs[0][1], costs[0][2]);
    for (int i = 1; i < costsSize; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2], INF) + costs[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2], INF) + costs[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1], INF) + costs[i][2];
        dp[i][3] = min(dp[i][0], dp[i][1], dp[i][2]);
    }
    return dp[costsSize-1][3];
}

