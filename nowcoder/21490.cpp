#include<stdio.h>
#include<stdlib.h>

int min(int a, int b, int c) {
	if (a <= b && a <= c) return a;
	if (b <= c && b <= a) return b;
	if (c <= a && c <= b) return c;
}

int max(int a, int b, int c) {
	if (a >= b && a >= c) return a;
	if (b >= c && b >= a) return b;
	if (c >= a && c >= b) return c;
}

int mid(int a, int b, int c) {
	if (c >= a && a >= b || b >= a && a >= c) return a;
	if (a >= b && b >= c || c >= b && b >= a) return b;
	if (a >= c && c >= b || b >= c && c >= a) return c;
}

int main(){
	int tmpa, tmpb, tmpc;
	while(scanf("%d %d %d", &tmpa, &tmpb, &tmpc) != EOF) {
		int a = min(tmpa, tmpb, tmpc);
		int b = mid(tmpa, tmpb, tmpc);
		int c = max(tmpa, tmpb, tmpc);
		
		if (a+b<=c) continue;
		
		if (a*a+b*b<c*c){
			printf("钝角三角形\n");
			continue;
		}
		if (a*a+b*b==c*c){
			printf("直角三角形\n");
			continue;
		}
		if (a*a+b*b>c*c){
			printf("锐角三角形\n");
			continue;
		}
		
	}
	return 0;
}