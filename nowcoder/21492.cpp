#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
	return a > b ? b : a;
}

int max(int a, int b) {
	return b > a ? b : a;
}

int main(){
	int tmpa, tmpb;
	while(scanf("%d %d", &tmpa, &tmpb) != EOF) {
		int a = min(tmpa, tmpb);
		int b = max(tmpa, tmpb);
		int ans = 1;
		for (int i = a / 2; i > 0; i--) {
			if (a % i == 0 && b % i == 0){
				ans = i;
				break;
			}
		}		
		printf("%d\n", ans);
	}
	return 0;
}