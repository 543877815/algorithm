#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int num;
    while(scanf("%d", &num) != EOF) {
		int size = (int)sqrt(num);
		int *mark = (int*)malloc(sizeof(int) * (size + 1));
		for (int i = 2; i < size + 1; i++) {
			mark[i] = 1; // 初始化标记全部为质数 
		}
		
		// 埃氏筛法
		for (int i = 2; i < size + 1; i++) { // 从2开始 
			for (int j = 2; i * j < size + 1; j++) { // 标记倍数 
				mark[i * j] = 0;
			}
		} 
		
		int count = 0; 
		for(int i = 2; i < size + 1; i++) {
			if (mark[i] == 1) {
				count++;
			}
		}
		
		int *sushu = (int *)malloc(sizeof(int) * count);
		int sushusize = 0;
		for(int i = 2; i < size + 1; i++) {
			if (mark[i] == 1) {
				sushu[sushusize++] = i;
			}
		}
		
		int ans = 0;
		int loc = 0; 
		while(num != 1) {
			if(loc >= sushusize) {
				ans += 1;
				break;
			}
			while(num%sushu[loc] == 0){
				ans++;
				num/=sushu[loc];
			}	
			loc++;
		}
		printf("%d\n", ans);
	} 
	return 0;
}