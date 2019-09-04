#include<stdio.h>
#include<stdlib.h>

int main(){
	int *arr = (int *)malloc(sizeof(int)*10);
	while(scanf("%d", &arr[0]) != EOF) {
		for (int i = 1; i < 10; i++) {
			scanf("%d", &arr[i]);
		}
		int max = -9999;
		for (int i = 0; i < 10; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		printf("max=%d\n", max);
	}
	return 0;
}