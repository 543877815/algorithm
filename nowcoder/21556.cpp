#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Num{
    int size;
    char num[1000];
};

int cmp(const void *a, const void *b){
    if(((Num*)a)->size != ((Num*)b)->size) return ((Num*)a)->size - ((Num*)b)->size;
    //int tmp = strcmp(((Num*)a)->num, ((Num*)b)->num);
    //if (tmp != 0) return strcmp(((Num*)a)->num, ((Num*)b)->num)
    else return strcmp(((Num*)a)->num, ((Num*)b)->num);
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        Num* nums = (Num *)malloc(sizeof(Num) * n);
        for (int i = 0; i < n; i++) {
            scanf("%s", nums[i].num);
            nums[i].size = strlen(nums[i].num);
        }
        qsort(nums, n, sizeof(Num), cmp);
        for (int i = 0; i < n; i++) {
            printf("%s\n", nums[i].num);
        }
    }
    
    return 0;
}