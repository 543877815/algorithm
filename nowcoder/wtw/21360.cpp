#include<stdio.h>
#include<stdlib.h>

int main() {
    int N, M;
    while(scanf("%d %d", &N, &M) != EOF) {
        int *arr = (int *)malloc(sizeof(int) * N);
        int *mark = (int *)malloc(sizeof(int) * N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
            mark[i] = -1;
        }
        for (int i = 0; i < N; i++) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                if (arr[i] == arr[j]) {
                    count++;
                }
            }
            mark[i] = count;
        }
        for (int i = 0; i < N; i++) {
            if (mark[i] == 0) {
                printf("BeiJu\n");
            } else {
                printf("%d\n", mark[i]);
            }
        }
    }
}