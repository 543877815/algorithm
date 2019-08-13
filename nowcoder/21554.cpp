#include<stdio.h>
#include<stdlib.h>

#define ISYEAR(x) x % 4 == 0 && x % 100 != 0 || x % 400 == 0 ? 1 : 0

int dayOfMonth[13][2] = {
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};

int counter[13][32];

int main(){
    int y, d;
    while(scanf("%d %d", &y, &d)!=EOF){
        int cnt = 1;
        int month = 0;
        int day = 0;
        for (int i = 1; i < 13; i++) {
            for (int j = 1; j <= dayOfMonth[i][ISYEAR(y)]; j++) {
                counter[i][j] = cnt;
                if (cnt == d) {
                    month = i;
                    day = j;
                }
                cnt++;
            }
        }
        printf("%d-%02d-%02d\n", y, month, day);
    }
    return 0;
}