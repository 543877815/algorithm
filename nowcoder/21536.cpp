#include<stdlib.h>
#include<stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        int **array = (int **) malloc (sizeof (int*) * n);
        for (int i = 0; i < n; i++) {
            array[i] = (int *) malloc (sizeof (int) * n);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &array[i][j]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int tmp = array[i][j];
                array[i][j] = array[j][i];
                array[j][i] = tmp;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", array[i][j]);
            }
            printf("\n");
        }
    }
}