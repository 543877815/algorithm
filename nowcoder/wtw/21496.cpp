#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int day = 30; 
	int total = 0;
	for(int i = 0; i < day; i++) {
		total += (int)pow(2, i);
	}
	printf("%d %d", day*10, total);
	return 0;
}