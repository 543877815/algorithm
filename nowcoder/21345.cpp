#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b){
	return *(int *) b - *(int *) a;
}

int main(){
	int total, num;
	while(scanf("%d", &total) != EOF) {
		scanf("%d", &num);
		int *arr = (int *)malloc(sizeof(int)*num);
		for (int i = 0; i < num; i++) {
			scanf("%d", &arr[i]);
		} 
		qsort(arr, num, sizeof(int), cmp);
		int ans = 0;
		int sum = 0;
		for (int i = 0; i < num; i++) {
			if (sum + arr[i] <= total) {
				sum += arr[i];
				ans++;
			}
		}
		if (sum < total) {
			printf("0\n");
			continue;
		}
		printf("%d\n", ans);
	}
	return 0;
}