#include<stdio.h>
int common(int a,int b){
    if(a==b)
    {
        return a;
    }
    else if(a>b){
        return common(a/2,b);
    }
    else{
        return common(a,b/2);
    }
}

int main(){
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        printf("%d\n",common(x,y));
    }
    return 0;
}
