#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[20];

int main(){
    while(gets(str)!=NULL){
        int array[4] = {0};
        int arraySize = 0;
        int weight = 1;
        for (int i = strlen(str)-1 ; i >=0; i--) {
            if (str[i] <= '9' && str[i] >= '0'){
                array[arraySize] += (str[i] - '0') * weight;
                weight *= 10;
            } else if (str[i] == '.') {
                arraySize++;
                weight = 1;
                if (arraySize >= 4){
                    printf("No1!");
                    break;
                }
            } else {
                printf("No2!");
                break;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            if (array[i] > 255 || array[i] < 0){
                printf("No!");
                break;
            }
            if (i == 3){
                printf("Yes!");
            }
        }
    }
    return 0;
}