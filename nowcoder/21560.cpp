#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[100];
bool mark[100];

int main(){
    while(gets(str) != NULL) {
        int length = strlen(str);
        for (int i = 0; i < 100; i++) {
            mark[i] = false;
        }
        for (int i = 0; i < length; i++) {
            if (mark[i] == true) continue;
            bool flag = false;
            for (int j = i + 1; j < length; j++) {
                if (str[i] == str[j]) {
                    if (mark[i] == false)
                        printf("%c:%d", str[i], i);
                    flag = true;
                    mark[i] = true;
                    mark[j] = true;
                    printf(",%c:%d", str[j], j);
                }
            }
            if (flag) {
                printf("\n");
            }
        }
    }
    return 0;
}