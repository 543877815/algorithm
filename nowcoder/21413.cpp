#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct string {
	char arr[100];
	int length;
} String;

int cmp(const void *a, const void *b) {
	return (*(String *)a).length - (*(String *)b).length;
}

int main(){
	int num, i;
	char stop[5] = "stop";
	while(scanf("%d\n", &num) != EOF) {
		String *string = (String*) malloc(sizeof(String) * num);
		for (i = 0; i < num; i++) {
			gets(string[i].arr);
			string[i].length = strlen(string[i].arr);
			if (strcmp(string[i].arr, stop) == 0) {
				break;
			}
		}
		num=i;
		qsort(string, num, sizeof(String), cmp);
		for (int i = 0; i < num; i++) {
			printf("%s\n", string[i].arr);
		}
	}
	return 0;
}