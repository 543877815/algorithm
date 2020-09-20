

int countPrimes(int n){
    if (n == 0 || n == 1) return 0;
    int *mark = (int *)malloc(sizeof(int) * (n+1));
    for (int i = 0; i <= n; i++) { // 标记为质数
        mark[i] = 1;
    }
    int bound = (int) sqrt(n);
    int num = 2; // 从2开始标记
    while(num <= bound){
        if (mark[num] == 1){
            for (int i = 2; num * i <= n; i++) {
                mark[num * i] = 0;
            }
        }
        num ++;
    }
    
    int ans = 0;
    for (int i = 2; i < n; i++) {
        if (mark[i] == 1) ans ++;
    }
    return ans;
}

