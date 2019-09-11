#include<stdio.h>
#include<stdlib.h>

int main() {
    int a;
    while(scanf("%d", &a) != EOF) {
        int sum = 0, x;
        for(int i = 0; i < 5; i++) {
            scanf("%d", &x);
            if (x < a) sum += x;
        }
        printf("%d\n", sum);
    }
    return 0;
}