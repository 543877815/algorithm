#include<stdio.h>
#include<stdlib.h>

int main(){
    char str[5];
    while(scanf("%s", str) != EOF) {
        str[4] = 0;
        for (int i = 0; i < 4; i++) {
            printf("%c", str[4-i-1]);
        }
        printf("\n");
    }
    
    return 0;
}