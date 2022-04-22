#include<stdio.h>
#include<stdlib.h>

int main(){
	int wanshu[60];
	int wanshusize = 0;
	int yinshu[60];
	int yinshusize = 0;
	for (int i = 2; i <= 60; i++) {
		int sum = 0;
		for (int j = 1; j <= i / 2; j++) {
			if (i % j == 0) {
				sum += j;
			}
		}
		if (sum > i) {
			yinshu[yinshusize++] = i;
		} else if (sum == i) {
			wanshu[wanshusize++] = i;
		}
	}
	
	printf("E:");
	for (int i = 0; i < wanshusize; i++) {
		printf(" %d", wanshu[i]);
	}
	
	printf("\n");
	printf("G:");
	
	for (int i = 0; i < yinshusize; i++) {
		printf(" %d", yinshu[i]);
	}
}