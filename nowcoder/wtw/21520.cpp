#include<stdio.h>
#include<stdlib.h>

int main(){
	int num;
	while(scanf("%d", &num) != EOF) {
		int *arr = (int *)malloc(sizeof(int) * num);
		for (int i = 0; i < num; i++) {
			scanf("%d", &arr[i]);
		}
		int sum = 0;
		for (int i = 0; i < num; i++) {
			int min1 = 999999;
			int min2 = 999999;
			int minIndex1 = -1;
			int minIndex2 = -1;
			for (int j = 0; j < num; j++) {
				if (min1 >= arr[j] && arr[j] != 0) {
					min2 = min1;
					minIndex2 = minIndex1;
					min1 = arr[j];
					minIndex1 = j;
					continue;
				}
				if (min2 >= arr[j] && arr[j] != 0) {
					min2 = arr[j];
					minIndex2 = j;
					continue;
				}
			}
			if (minIndex1 != -1 && minIndex2 != -1) {
				sum += min1 + min2;
				arr[minIndex1] = 0;
				arr[minIndex2] = min1 + min2; 
			} 
		}
		printf("%d\n", sum);
	}
}