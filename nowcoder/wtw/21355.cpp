#include<stdio.h>
#define width 3000

int main(){
	int i,j;
	int k,r,t;
	int N;
	int d[width];
	while(scanf("%d", &N) != EOF) {
		t = 0;
		for (int i = 0; i < width; i++) {
			d[i] = 0; // 初始化 
		}
		d[0] = 1;
		for (i = 1; i <= N; i++) {
			k = 0; // 进位 
			for (j = 0; j <= t; j++) { // 个位开始 
				r=(d[j]*i+k)/10; // 进位保存 
				d[j]=(d[j]*i+k)%10; // 个位保存
				k = r; 
			}
			while(k!=0){
				d[++t] = k % 10;
				k /= 10;
			}
		}
		for (int i = t; i >= 0; i--) {
			printf("%d", d[i]);
		}
		printf("\n");
	}
}