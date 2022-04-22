#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1001];
int main(){
    while(gets(str)!=NULL) {
        int length = strlen(str);
        int i ;
        for (i = 0; i < length; i++) {
            if (str[i] != str[length-1-i]){
                printf("No!\n");
                break;
            }
        }
        if (i == length) printf("Yes!\n");
    }  
}