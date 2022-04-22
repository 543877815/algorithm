#include<stdio.h>
#include<stdlib.h>

long long int F(int n) {
	if (n == 1) return 1;
	return F(n - 1) * n;
}

int main(){
    int num;
    while(scanf("%d", &num) != EOF) {
        printf("%lld\n", F(num));
    }
    return 0;
}