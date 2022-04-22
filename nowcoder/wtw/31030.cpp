#include<stdio.h>
#include<stdlib.h>

int main(){
	for (int i = 1; i < 256; i++) {
		int pow = i * i;
		int *arr = (int *)malloc(sizeof(int) * 6);
		int size = 0;
		while(pow != 0) {
			arr[size++] = pow % 10;
			pow /= 10;
		}
		int j;
		for (j = 0; j < size / 2; j++) {
			if (arr[j] != arr[size - 1 - j]) break;
		}
		if (j == size / 2) printf("%d\n", i);
	}
	return 0;
}