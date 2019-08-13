#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[100];
int main(){
    while(gets(str) != NULL) {
        int length = strlen(str);
        for (int i = 0; i < length; i++) {
            int num = str[i] - '0' + 48;
            int nums[20];
            int numsSize = 0;
            int odd = 0;
            while(num != 0) {
                int carry = num % 2;
                if (carry == 1) odd++;
                num /= 2;
                nums[numsSize++] = carry;
            }
            int flag = 0;
            if (odd % 2 == 0) {
                printf("1");
                flag = 1;
            }
            for (int i = 0; i < 8 - numsSize - flag; i++) {
                printf("0");
            }
            for (int i = 0; i < numsSize; i++) {
                printf("%d", nums[numsSize - 1 - i]);
            }
            printf("\n");
        }
    }
    
    
    return 0;
}