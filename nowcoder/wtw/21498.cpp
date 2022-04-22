#include<stdio.h>
#include<stdlib.h>

int main(){
	int a, n;
	while(scanf("%d %d", &a, &n) != EOF) {
		int ans[1000];
		int size = 0;
		int tmp = 0; // 暂存 
		int loc = 0;   // 进位 
		int carry = 0; // 余数 
		for (int i = 0; i < n; i++) {
			tmp = a * (n - i) + loc; 
			carry = tmp % 10;
			loc = tmp / 10;
			ans[size++] = carry;
		}
		while(loc!=0) {
			tmp = loc;
			carry = tmp % 10;
			loc = tmp / 10;
			ans[size++] = carry;
		}
		for (int i = size - 1; i >= 0; i--) {
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	
	return 0;
}