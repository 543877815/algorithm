#include<stdio.h>
#include<stdlib.h>

int dp[1000001];
int main(){
	int num,i;
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(i=3;i<=1000000;i++){
        dp[i]=0;
        if(i%2!=0)
            dp[i]=(dp[i-1])%1000000000;
        else
            dp[i]=(dp[i-1]+dp[i/2])%1000000000;
    }
    while(scanf("%d",&num)!=EOF){
    	printf("%d\n",dp[num]);
	}
	return 0;
}