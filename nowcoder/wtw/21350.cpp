#include<stdio.h>
#include<stdlib.h>

int isYear(int year) {
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int main(){
	int *arr = (int *)malloc(sizeof(int) * 13);
	arr[0] = 0;
	arr[1] = 31;
	arr[2] = 28;
	arr[3] = 31;
	arr[4] = 30;
	arr[5] = 31;
	arr[6] = 30;
	arr[7] = 31;
	arr[8] = 31;
	arr[9] = 30;
	arr[10] = 31;
	arr[11] = 30;
	arr[12] = 31;
	int year, month, day;
	while(scanf("%d %d %d", &year, &month, &day) != EOF) {
		int sum = 0;
		if (isYear(year) == 1) arr[2] = 29;
		for (int i = 1; i < month; i++) {
			sum += arr[i];
		}
		sum += day;
		printf("%d\n", sum);
	}
}