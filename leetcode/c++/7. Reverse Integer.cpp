# include <stdio. h>
# include <stdlib. h>
# include <math.h>
int reverse(int x){
    char str[50];   
    int positive = -1;
    if (x == 0){
        return 0;
    }else if (x > 0){
        positive = 1;
    }else {
        positive = 0;
    }
    x = llabs(x);
    int zeroFlag = 1;
    int i = 0;
    while(x!= 0){
        int digit = x % 10;
        if (zeroFlag == 1 && digit == 0){
            
        }else{
            zeroFlag = 0;
            char digit_str[10];
            sprintf(digit_str, "%d", digit);
            str[i] = digit_str[0];
            i ++ ;
        }
        x = x / 10;
    }
    if(i>10){
        return 0;
    }
    if(i==10){
        char max[20];
        sprintf(max, "%d", (int) pow(2,31) -1);
        if(strcmp(str,max) > 0){
            return 0;
        }
    }
    int num = positive == 1 ? atoi(str) : - atoi(str);
    return num;

}

