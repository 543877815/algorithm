#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int cmp(const void *a, const void *b) {
	return *(char*)a- *(char*)b;
}

int main(){
	char string[1000];
	while(scanf("%s", string) != EOF) {
		int length = strlen(string);
		qsort(string, length, sizeof(char), cmp);
		printf("%s\n", string);		
	}
	return 0;
}