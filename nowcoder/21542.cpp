#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b){
    return (*(int *)a - *(int *)b);
}


int main(){
    int n = 0;
    while(scanf("%d", &n) != EOF) {
        int *arr = (int *) malloc(sizeof(int) * n) ;
        for (int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        qsort(arr, n, sizeof(int), cmp);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}