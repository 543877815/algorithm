#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n != 0) {
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            int num = 0;
            for (int i = 1; i * i <= x; i++ ){
                if (i * i == x) {
                    num++;
                    break;
                }
                if(x % i == 0) num += 2;
            }
            printf("%d\n", num);
        }
    }
    
    return 0;
}