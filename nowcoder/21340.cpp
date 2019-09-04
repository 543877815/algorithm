#include<stdio.h>
#include<stdlib.h>

typedef struct student {
	int num;
	int grade;
} Student;

int cmp(const void *a, const void *b) {
    if (((Student *)a)->grade != ((Student *)b)->grade)
	    return ((Student *)a)->grade - ((Student *)b)->grade;
    else return ((Student *)a)->num - ((Student *)b)->num;
}

int main(){
	int num;
	while(scanf("%d", &num) != EOF) {
		Student * arr = (Student *)malloc(sizeof(Student)* num);
		for (int i = 0; i < num; i++) {
			scanf("%d %d", &arr[i].num, &arr[i].grade);
		}
		qsort(arr, num, sizeof(Student), cmp);	
		for (int i = 0; i < num; i++) {
			printf("%d %d\n", arr[i].num, arr[i].grade);
		}
	}
	return 0;
} 