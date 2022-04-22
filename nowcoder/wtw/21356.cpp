#include<stdio.h>
#include<stdlib.h>

int main() {
    int size, num;
    while(scanf("%d %d", &size, &num) != EOF) {
        int *arr = (int *)malloc(sizeof(int)*(size+1));
        for (int i = 0; i <= size; i++) {
            arr[i] = 1;
        }
        int x, y;
        for (int i = 0; i < num; i++) {
            scanf("%d %d", &x, &y);
            for (int j = x; j <= y; j++) {
                arr[j] = 0;
            }
        }
        int count = 0;
        for (int i = 0; i <= size; i++) {
            if (arr[i] == 1) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}