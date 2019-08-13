int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= c && b <= a) return b;
    if (c <= a && c <= b) return c;
    return 0;
}

int nthUglyNumber(int n){
    int *arr = (int *)malloc(sizeof(int) * (n + 1));
    int i2 = 1, i3 = 1, i5 = 1, i = 2;
    arr[1] = 1;
    int num = 1;
    while(i <= n) {
        int minN = min(arr[i2]*2, arr[i3]*3, arr[i5]*5);
        arr[i] = minN;
        if(minN == arr[i2] * 2)i2++;
        if(minN == arr[i3] * 3)i3++;
        if(minN == arr[i5] * 5)i5++;
        i++;
    }
    return arr[n];
}

