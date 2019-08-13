#include <stdio.h>
#include <stdlib.h>


int str[10];

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        int size = 0;
        while(n !=0){
            str[size++] = n % 8;
            n /= 8;
        }
        for(int i = size - 1; i >= 0; i--) {
            printf("%d", str[i]);
        }
        printf("\n");
    }
    return 0;
}