#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        int **arr = (int **) malloc(sizeof(int *) * n);
        for (int i = 0; i < n; i++) {
            arr[i] = (int *) malloc(sizeof(int) * n);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if(j == 0 || j == i) arr[i][j] = 1;
                else{
                    if(i > 1 && j > 0) {
                        arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
                    }
                }
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}