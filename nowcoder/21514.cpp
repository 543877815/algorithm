#include<stdio.h>
#include<stdlib.h>

int main() {
    int num;
    while(scanf("%d", &num) != EOF) {
        int *mark = (int *)malloc(sizeof(int)*(num+1));
        for (int i = 0; i <= num; i++){
            mark[i] = 1;     
        }
        for (int i = 2; i * i <= num; i++) {
            if (mark[i] == 0) continue;
            int j = 2;
            while(i * j <= num) {
                mark[i * j] = 0;
                j++;
            }
        }
        int flag = 0;
        for (int i = 2; i < num; i++) {
            if (mark[i] == 1 && i % 10 == 1) {
                printf("%d " , i);
                flag = 1;
            }
        }
        if (flag == 0) printf("-1");
        printf("\n");
    }
    return 0;
}