#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	double x1, y1, z1, x2, y2, z2;
	while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2) != EOF) {
		double r = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
		double pi = acos(-1);
		double square = 4.0 / 3.0 * pi * r * r * r;
		printf("%.3lf %.3lf\n", r, square);
	}
	return 0;
}