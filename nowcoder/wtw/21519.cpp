#include<stdio.h>
#include<stdlib.h>

int main(){
	int num;
	while(scanf("%d", &num) != EOF) {
		int *arr = (int *)malloc(sizeof(int)*32);
		int size = 0; 
		while(num != 0) {
			arr[size++] = num % 2;
			num /= 2;
		}
		
		for (int i = size - 1; i >= 0; i--) {
			printf("%d", arr[i]);
		}
		printf("\n");
	}
	return 0;
}