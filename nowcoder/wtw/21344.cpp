#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    while(scanf("%d", &num) != EOF) {
		int min = 10001;
		int max = -10001;
		int tmp;
		for (int i = 0; i < num; i++) {
			scanf("%d", &tmp);
			if (tmp > max) max = tmp;
			if (tmp < min) min = tmp;
		}
		printf("%d %d\n", max, min);
		
    }
    return 0;
}