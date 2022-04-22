#include<stdio.h>
#include<stdlib.h>

int main(){
	int a0, a1, p, q, k;
	while(scanf("%d %d %d %d %d", &a0, &a1, &p, &q, &k) != EOF) {
		int *arr = (int *)malloc(sizeof(int) * (k + 1));
		arr[0] = a0;
		arr[1] = a1;
		for (int i = 2; i <= k; i++) {
			arr[i] = p * arr[i - 1] + q * arr[i - 2];
			if (arr[i] > 10000) arr[i] %= 10000;
		}
		int ans = arr[k] % 10000;
		printf("%d", ans);
	}
}