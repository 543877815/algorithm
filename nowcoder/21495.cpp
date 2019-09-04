#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char dst[1000];
	char src[1000];
	while(scanf("%s %s", dst, src) != EOF) {
		int lengthDst = strlen(dst);
		int lengthSrc = strlen(src);
		for(int i = 0; i < lengthSrc; i++) {
			dst[lengthDst + i] = src[i];
		}
		dst[lengthDst+lengthSrc] = 0;
		printf("%s\n", dst);
	}
	return 0;
}