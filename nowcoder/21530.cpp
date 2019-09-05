#include <stdio.h>
#include <stdlib.h>

typedef struct NUM {
	int a;
	int b;
} NUM;

int cmp(const void *a, const void *b) {
	if((*(NUM *)a).a != (*(NUM *)b).a)  return (*(NUM *)a).a - (*(NUM *)b).a;
	else return (*(NUM *)a).b - (*(NUM *)b).b;
}

int main(){
	int num;
	while(scanf("%d", &num) != EOF) {
		NUM * arr = (NUM *)malloc(sizeof(NUM) * num);
		for (int i = 0; i < num; i++) {
			scanf("%d %d", &arr[i].a, &arr[i].b);
		}	
		qsort(arr, num, sizeof(NUM), cmp);
		
		printf("%d %d\n", arr[0].a, arr[0].b);
	}
	return 0;
}