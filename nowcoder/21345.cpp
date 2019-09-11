#include<stdio.h>
#include<stdlib.h>

int min(int a, int b) {
	return a > b ? b : a;
}

typedef struct E {
	int w;
	int v;
} List;

int main(){
	int total, num;
	while(scanf("%d\n%d", &total, &num) != EOF) {
		int *dp = (int *)malloc(sizeof(int)*(total+1));
		List *list = (List *)malloc(sizeof(List)*(num+1));
		for (int i = 1; i <= total; i++) {
			dp[i] = 1000;
		}
		dp[0] = 0;
		for (int i = 1; i <= num; i++) {
			scanf("%d", &list[i].w);
			list[i].v = 1;
			for (int j = total; j >= list[i].w; j--) {
				dp[j] = min(dp[j], dp[j-list[i].w] + list[i].v);
			}
		} 
		if (dp[total] == 1000) dp[total] = 0;
		printf("%d\n", dp[total]);
		
	}
	return 0;
}
