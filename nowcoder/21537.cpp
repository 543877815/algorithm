#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    while(gets(str) != NULL){
        int length = strlen(str);
        int array[100] = {0};
        int j = 0;
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' '){
                array[j] = count;
                j++;
                count=0;
            }else if(str[i] == '.'){
                array[j] = count;
                j++;
                break;
            }else{
                count++;
            }
        }
        
        for (int i = 0; i < j; i++) {
            printf("%d ", array[i]);
        }
    }
}


