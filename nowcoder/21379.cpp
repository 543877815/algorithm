#include<stdio.h>
#include<stdlib.h>

int main() {
    int num;
    while(scanf("%d", &num) != EOF) {
        int *dp = (int *)malloc(sizeof(int) * (num+1));
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= num; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        printf("%d\n", dp[num]);
    }
    return 0;
}