#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, m;
    while(scanf("%d", &n) != EOF) {
        int *arr = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &m);
        int *tmp = (int *)malloc(sizeof(int) * m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &tmp[i]);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (tmp[i] == arr[j]) {
                    printf("YES\n");
                    break;
                }
                if (j == n - 1 && tmp[i] != arr[j]) {
                    printf("NO\n");
                }
            }
        }
    }
    return 0;
}