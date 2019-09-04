#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[100];
    int score;
};

int cmp1(const void *a, const void *b){
    return ((Student*)a)->score - ((Student*)b)->score;
}

int cmp2(const void *a, const void *b){
    return ((Student*)b)->score - ((Student*)a)->score;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        int x;
        scanf("%d", &x);
        Student * students = (Student *)malloc(sizeof(Student) * n);
        for (int i = 0; i < n; i++) {
            scanf("%s %d", students[i].name, &students[i].score);
        }
        if (x == 0) qsort(students, n, sizeof(Student), cmp2);
        else if (x == 1) qsort(students, n, sizeof(Student), cmp1);
        
        for (int i = 0; i < n; i++) {
            printf("%s %d\n", students[i].name, students[i].score);
        }
    }
    return 0;
}