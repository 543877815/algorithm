#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char string[31];
    int num[31];
    int res[2000];
    while(scanf("%s", string) != EOF) {
        int length = strlen(string);
        for (int i = 0; i < length; i++) {
            num[i] = string[i] - '0';
        }
        int index = 0; // 结果数组游标
        for (int i = 0; i < length;) {
            int remain = 0, temp = 0; // 余数
            for (int j = i; j < length; j++) { // 控制除法运算，竖式除法，
                temp = (10 * remain + num[j]) % 2; 
                num[j] = (10 * remain + num[j]) / 2;
                remain = temp;
            } 
            res[index] = remain;
            index ++;
            while(num[i] == 0) i++;
        }
        
        for (int i = index - 1; i >= 0; i--) {
            printf("%d", res[i]);
        } 
        printf("\n");
    }
    return 0;
}