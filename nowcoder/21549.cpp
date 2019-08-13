#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        int tmp = n;
        int weight = 1;
        while(tmp != 0){
            weight *= 10;
            tmp /= 10;
        }
        int lower = n * n % weight;
        
        if (lower != n) printf("No!\n");
        else printf("Yes!\n");
    }
    return 0;
}