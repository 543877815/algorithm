#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char *arr = (char *)malloc(sizeof(char) * 81);
	while(gets(arr)) {
		int length = strlen(arr);
		for (int i = 0; i < length; i++) {
			if (arr[i] == 'z') {
				arr[i] = 'a';
				continue;
			}
			if (arr[i] == 'Z') {
				arr[i] = 'A';
				continue;
			}
			if (arr[i] >= 'a' && arr[i] <= 'z' || arr[i] >= 'A' && arr[i] <= 'Z') {
				arr[i] += 1;
			}
		}
		printf("%s\n", arr);
	} 
	return 0;
}