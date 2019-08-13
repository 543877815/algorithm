#include <stdio.h>
#include <stdlib.h>

int jiecheng(int x){
    if (x == 1){
        return 1;
    } else if (x == 2){
        return 2;
    }
    return x * jiecheng(x - 1);
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int ans1 = 0, ans2 = 0;
        for (int i = 1; i <= n; i = i + 2) {
            ans1 += jiecheng(i);
        }
        for (int i = 2; i <= n; i = i + 2) {
            ans2 += jiecheng(i);
        }
        printf("%d %d\n", ans1, ans2);
    }
}