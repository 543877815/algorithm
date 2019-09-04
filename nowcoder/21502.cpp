#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int left[2][3];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &left[i][j]);
		}
	}
	int right[3][2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &right[i][j]);
		}
	}
	int ans[2][2]; 
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			int sum = 0;
			for (int m = 0; m < 3; m++) {
				sum += left[i][m] * right[m][j];
			}
			ans[i][j] = sum; 
			printf("%d ", ans[i][j]);
		} 
		printf("\n");
	}
}