#include <stdio.h>
#include <stdlib.h>


int main(){
	int num;
	while(scanf("%d", &num) != EOF) {
		for (int i = 1; i <= num; i++) {
			int total = 0;
			for (int j = 1; j <= i / 2; j++) {
				if (i % j == 0) total+=j;
			
			}
			if (i == total) {
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	return 0;
}