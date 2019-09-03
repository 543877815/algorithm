#include<stdio.h>
#include<stdlib.h>

int main(){
	int num;
	while(scanf("%d", &num) != EOF) {
		int min = 9999;
		int max = -9999;
        int minIndex = -1;
        int maxIndex = -1;
		int *arr = (int*)malloc(sizeof(int)*num);
		for (int i = 0; i < num; i++) {
			scanf("%d", &arr[i]);
			if(arr[i] > max) {
				max = arr[i];
                maxIndex = i;
			}
			if(arr[i] < min) {
				min = arr[i];
                minIndex = i;
			}
		}
		
        int tmp = arr[maxIndex];
        arr[maxIndex] = arr[minIndex];
        arr[minIndex] = tmp;
        
        for (int i = 0; i < num; i++) {
            printf("%d ", arr[i]);
        }
        
		printf("\n");
	}
	
	return 0;
}