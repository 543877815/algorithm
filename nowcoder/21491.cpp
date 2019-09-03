#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main(){
	int num = 20;
	int *arr = (int*)malloc(sizeof(int)*num);
	while(scanf("%d", &arr[0])!=EOF){
		for (int i = 1; i < num; i++) {
			scanf("%d", &arr[i]);
		}
		qsort(arr, num, sizeof(int), cmp);
		int ans = arr[0];
		int tmp = arr[0];
		int maxCount = 0;
		int count = 0;
		for (int i = 0; i < num; i++) {
			if (arr[i]!=tmp) {
				tmp = arr[i];
				count = 0;
			}
			
			count ++;
			
			if (count > maxCount) {
				maxCount = count;
				ans = arr[i];
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}