#include<stdio.h>
#include<string.h>

int main(){
	for (int i = 0; i < 10; i++) { // a 
		for (int j = 0; j < 10; j++) { // b
			for (int k = 0; k < 10; k++) { // c
				if (i * 100 + j * 10 + k + j * 100 + k * 10 + k == 532) {
					printf("%d %d %d\n", i, j, k);
				}
			}
		}
	}
	return 0;
}