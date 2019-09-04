#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char string[1000];
	char chara;
	while(scanf("%s %c", string, &chara) != EOF) {
		int length = strlen(string);
		int count = 0;
		for (int i = 0; string[i]!=0; i++) {
			if (string[i] == chara) {
				count ++;
				for (int j = i; j < length - 1; j++) {
					string[j] = string[j+1];
				}
				i--;
				string[length - count] = 0;
			}
		}
		printf("%s\n", string);
	}
	return 0;
}