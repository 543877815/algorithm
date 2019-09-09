#include<stdio.h>
#include<stdlib.h>

int main(){
	int min = 0; 
	int max = 5 * 8 + 10 * 4 + 18 * 6;
	int *arr = (int *)malloc(sizeof(int)*(max-min));
	for (int i = 0; i < max - min; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 4; j++) {
			for (int k = 0; k <= 6; k++) {
				arr[i*8+j*10+k*18]++;
			}
		}
	} 
	int count = 0;
	for (int i = 0; i < max - min; i++) {
		if (arr[i] != 0) count ++;
	}
	printf("%d", count);
	return 0;
}