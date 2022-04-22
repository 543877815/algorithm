#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char map[8][5] = {"abc1", "def1", "ghi1", "jkl1", "mno1", "pqrs", "tuv1", "wxyz"}; // 用1补齐 
    char *arr = (char *)malloc(sizeof(char) * 100);
    while(scanf("%s", arr) != EOF) {
    	int last = -1;
    	int flag = -1;
    	int ans = 0;
    	int length = strlen(arr);
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k < 4; k++) {
					if (arr[i] == map[j][k]) {
						ans += k + 1;
						if (last == j) {
							ans += 2;
						}
						last = j;
						flag = 0;
						break;
					}
				}
				if (flag == 0) {
					flag = -1;;
					break;
				}
			}
		}
		printf("%d\n", ans);
	} 
	return 0;
}