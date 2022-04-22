#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b;
	while(scanf("%d %d", &a, &b) != EOF) {
		int sum = 0;
		for (int i = a; i != 0; i /= 10) {
			for (int j = b; j != 0; j /= 10) {
				sum += (i % 10) * (j % 10);
			}
		}
		printf("%d\n", sum);
		
	}
	return 0;
}