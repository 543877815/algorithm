#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        int *F = (int *) malloc (sizeof (int) * (n + 1));
        F[1] = 1;
        F[2] = 2;
        for (int i = 3; i <= n ; i++) {
            F[i] = F[i-1] + F[i-2];
        }
        printf("%d", F[n]);
    }
}