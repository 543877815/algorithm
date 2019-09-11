#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int num;
    while(scanf("%d", &num) != EOF) {
        int *arr = (int *)malloc(sizeof(int) * num);
        for (int i = 0; i < num; i++) {
            scanf("%d", &arr[i]);
        }
        int k;
        scanf("%d", &k);
        qsort(arr, num, sizeof(int), cmp);
        for (int i = 0; i < num - 1; i++) {
            if (arr[i] < arr[i+1]) {
                k--;
                if (k == 1) {
                    printf("%d\n", arr[i+1]);
                    break;
                }
            }
        }
    }
}