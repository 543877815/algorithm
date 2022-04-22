#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int num;
	while(scanf("%d", &num) != EOF) {
		if (num == 2 || num == 3) {
			printf("yes\n");
			continue;
		}
		if (num <= 1) {
			printf("no\n");
		}
		for (int i = 2; i <= (int) sqrt(num); i++) {
			if (num % i == 0) {
				printf("no\n");
				break;
			} else {
				if (i == (int) sqrt(num)) {
					printf("yes\n");
				}
			}
			
		}
	}
	return 0;
}