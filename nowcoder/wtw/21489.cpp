#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;
	while(scanf("%d", &num) != EOF) {
		int *arr = (int *)malloc(sizeof(int) * num);
		for (int i = 0; i < num; i++) {
			scanf("%d", &arr[i]);
		}
		int n;
		scanf("%d", &n);
		int index = -1;
		for (int i = 0; i < num; i++) {
			if (arr[i] == n) {
				index = i;
				break;
			}
		}
		printf("%d\n", index);
	}
	
	return 0;
}