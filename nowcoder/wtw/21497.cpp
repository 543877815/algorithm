#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char string[1000];
	while(scanf("%s", string) != EOF) {
		int length = strlen(string);
		for (int i = length - 1; i >= 0; i--) {
			printf("%c", string[i]);
		}
		printf("\n");
	}
	
	
	return 0;
}