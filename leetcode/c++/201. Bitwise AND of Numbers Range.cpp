// 超时

int rangeBitwiseAnd(int m, int n){
    int num = n;
    for (int i = m; i < n; i++) {
        num = num & i;
    }
    return num;
}

// 通过


int rangeBitwiseAnd(int m, int n){
    int a = 0, b = 0;
    int tmp = 0;
    long long int count = 1;
    while(tmp < 32) {
        if (count <= m && count * 2 >= m) a = tmp + 1;
        if (count <= n && count * 2 >= n) b = tmp + 1;
        count *= 2;
        tmp ++;
    }
    printf("%d %d", a, b);
    if (a == b) {
        int num = n;
        for (int i = m; i < n; i++) {
            num = num & i;
        }
        return num;
    } 
    return 0;
}

