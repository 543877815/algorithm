#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int num;
    while(scanf("%d", &num) != EOF) {
    	if (num == 0) return 0;
        int *arr = (int *)malloc(sizeof(int) * num);
        for (int i = 0; i < num; i++) {
            scanf("%d", &arr[i]);
        }
        qsort(arr, num, sizeof(int), cmp);
        if (num % 2 == 1){
            printf("%d\n", arr[num / 2]);
        } else {
            printf("%d\n", (arr[num / 2] + arr[num / 2 - 1]) / 2);
        }
    }
    return 0;
}