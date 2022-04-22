#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str1[20];
char str2[20];

int abs(int x) {
    return x > 0 ? x : -x;
}

int main(){
    while(scanf("%s %s", str1, str2) != EOF) {
        int positive1 = 1, positive2 = 1;
        if (str1[0] == '-') {
            positive1 = 0;
        }
        if (str2[0] == '-') {
            positive2 = 0;
        }
        
        int num1=0;
        int num2=0;
        
        int length1 = strlen(str1);
        int length2 = strlen(str2);
        
        int weight1 = 1;
        int weight2 = 1;
                
        for (int i = length1 - 1; i >= 0; i--) { //从最后开始读
            if(str1[i] == ',') {
                continue;
            } else if(str1[i] >= '0' && str1[i] <= '9') {
                num1 = num1 + weight1 * (str1[i] - '0');
                weight1 *= 10;
                //printf("%d %d\n", arr1[size1], size1);
            } 
        }
        
        for (int i = length2 - 1; i >= 0; i--) { //从最后开始读
            if(str2[i] == ',') {
                continue;
            } else if(str2[i] >= '0' && str2[i] <= '9') {
                num2 = num2 + weight2 * (str2[i] - '0');
                weight2 *= 10;
            } 
        }
        
        if (!positive1) num1 = -num1;
        if (!positive2) num2 = -num2;
        
        printf("%d\n", num1+num2);
        
                
    }
    return 0;
}