#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, m;
    while(scanf("%d %d",&n, &m)!= EOF ){
        int **arr = (int **)malloc(sizeof(int*)*n);
        for (int i = 0 ; i < n; i++) {
            arr[i] = (int*)malloc(sizeof(int)*m);
        }
        
        for(int i = 0; i < n; i++) {
            int maxIndex = -1;
            int max = -999;
            for (int j = 0; j < m; j++) {
                scanf("%d", &arr[i][j]);
                if (arr[i][j] > max) {
                    max = arr[i][j];
                    maxIndex = j;
                }
            }
            
            for (int j = 0; j < m; j++) {
                if (maxIndex != j) {
                    max += arr[i][j];
                }
            }
            arr[i][maxIndex] = max;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        
        
    }
    return 0;
}