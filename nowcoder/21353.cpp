#include<stdio.h>
#include<stdlib.h>

long int max (long int a, long int b) {
    return a > b ? a : b;
}

int main(){
    int num;
    while(scanf("%d", &num) != EOF) {
        long int sum = 0, Max = -9999999, x;
        for (int i = 0; i < num; i++) {
            scanf("%ld", &x);
            sum = max(sum + x, x);
            Max = max(Max, sum);
        }
        printf("%ld\n", Max);
        
    }
    return 0;
}
