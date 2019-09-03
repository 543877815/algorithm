
#include <stdio.h>
#include <stdlib.h>


int main(){
	int num;
	while(scanf("%d", &num) != EOF) {
		for (int i = 0; i * 5 < num; i++) {
			for (int j = 0; j * 3 < num; j++) {
				for (int k = 0; k < num * 3; k++) {
					if (i * 5 * 3+ j * 3 * 3+ k  < 3 * num && i + k + j == 100) {
						printf("x=%d,y=%d,z=%d\n",i,j,k);
					}
				}
			}
		}
	}
	return 0; 
}