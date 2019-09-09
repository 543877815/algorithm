#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	for (int i = 1000; i <= 10000 / 9; i++) {
		int tmp = i;
		int size = 0;
		int ans = i / 1000 + i / 100 % 10 * 10 + i / 10 % 10 * 100 + i / 1 % 10 * 1000;
		if (ans == i * 9) printf("%d\n", i);
	}
	return 0;
}