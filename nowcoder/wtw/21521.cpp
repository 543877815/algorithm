#include<stdio.h>
#include<stdlib.h>

int main() {
    int num;
    while(scanf("%d", &num) != EOF) {
        int x, even = 0, odd = 0;
        for (int i = 0; i < num; i++) {
            scanf("%d", &x);
            if (x % 2 == 1) odd ++;
            else even ++;
        }
        if (even > odd) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}