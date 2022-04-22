#include<stdio.h>
#include<stdlib.h>

int main(){
    int n = 4;
    int m = 5;
    // n*n矩阵
    int **arr = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < m; i++) {
        arr[i] = (int *) malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // 2*n数组
    int **max = (int **) malloc(sizeof(int *) *2);
    for (int i = 0; i < 2; i++) {
        max[i] = (int *) malloc(sizeof(int) * n);
    }

    for (int i = 0; i < m; i++) { // 列
        int max1 = -9998;
        int maxIndex1 = -1;
        int max2 = -9999;
        int maxIndex2 = -1;
        for(int j = 0; j < n; j++) { // 行   
            if (arr[j][i] > max1 && arr[j][i] > max2 ){
                max2 = max1;
                maxIndex2 = maxIndex1;
                max1 = arr[j][i];
                maxIndex1 = j;
            } else if (arr[j][i] >= max2 && arr[j][i] <= max1) {
                max2 = arr[j][i];
                maxIndex2 = j;
            } 
        }
        max[1][i] = maxIndex1 > maxIndex2 ? arr[maxIndex1][i] : arr[maxIndex2][i];
        max[0][i] = maxIndex1 > maxIndex2 ? arr[maxIndex2][i] : arr[maxIndex1][i];
    }
    
    for (int i = 0; i < 2; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d",max[i][j]);
            if (j!=m-1)printf(" ");
        }
        printf("\n");
    }
    
    //}
    return 0;
}