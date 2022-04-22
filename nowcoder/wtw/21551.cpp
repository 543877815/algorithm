#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Worker{
    int num;
    char name[11];
    int age;
};

int cmp(const void* a, const void* b){
    if(((Worker *)a)->age != ((Worker *)b)->age) return ((Worker *)a)->age - ((Worker *)b)->age;
    if(((Worker *)a)->num != ((Worker *)b)->num) return ((Worker *)a)->num - ((Worker *)b)->num;
    int tmp = strcmp(((Worker *)a)->name, ((Worker *)b)->name);
    if(tmp != 0) return strcmp(((Worker *)a)->name, ((Worker *)b)->name); 
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        Worker * workers = (Worker*)malloc(sizeof(Worker) * n);
        for (int i = 0; i < n; i++) {
            scanf("%d %s %d", &workers[i].num, workers[i].name, &workers[i].age);
        }
        qsort(workers, n, sizeof(Worker), cmp);
        for (int i = 0; i < 3; i++) {
            printf("%d %s %d\n", workers[i].num, workers[i].name, workers[i].age);
        }
    }
    return 0;
}