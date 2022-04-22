#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        int ** arr = (int **) malloc(sizeof (int*) * n);
        for (int i = 0; i < n; i++) {
            arr[i] = (int *) malloc(sizeof(int) * n);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (!flag) break;
            for (int j = i; j < n; j++) {
                if (arr[i][j] != arr[j][i]) {
                    flag = false;
                    printf("No!");
                    break;
                }
            }
        }
        if (flag) {
            printf("Yes!");
        }
        printf("\n");
    }
    
    return 0;
}