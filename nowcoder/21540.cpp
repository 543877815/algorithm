#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[100], str2[100];
    while(scanf("%s %s", str1, str2)!=EOF){
        int length1 = strlen(str1);
        int length2 = strlen(str2);
        char *str = (char *) malloc (sizeof(char) * (length1 + length2));
        for (int i = 0 ; i < length1; i++) {
            str[i] = str1[i];
        }
        for (int i = 0; i < length2; i++) {
            str[i + length1] = str2[i];
        }
        
        for (int i = 0; i < length1 + length2; i++) {
            printf("%c", str[i]);
        }
    }
    return 0;
}