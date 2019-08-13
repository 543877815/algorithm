

bool divisorGame(int N){
    if (N <= 1) return false;
    if (N == 2) return true;
    int *dp = (int *) malloc (sizeof(int) * (N+1));
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i < N + 1; i++) {
        dp[i] = 0;
        for (int j = 1; j < i / 2; j++) {
            if (i % j == 0 && dp[i-j] == 0){
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[N];
}

