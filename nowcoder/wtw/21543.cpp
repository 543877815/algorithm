#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
} 


int main(){
    int n; 
    while(scanf("%d", &n) != EOF){
        if (n == 1) {
            int x;
            scanf("%d", &x);
            printf("%d\n", x);
            printf("-1\n");
            continue;
        }
        
        int *arr = (int *) malloc (sizeof (int) * n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        qsort(arr, n, sizeof(int), cmp);
        
        printf("%d\n", arr[n-1]);
        for (int i = 0; i < n -1; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    return 0;
    
}