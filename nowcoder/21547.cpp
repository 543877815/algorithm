#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	char name[101];
	int age;
	int score;
};

int cmp(const void *a, const void *b){
	if (((Student *)a)->score != ((Student *)b)->score) return ((Student *)a)->score - ((Student *)b)->score;
	int tmp = strcmp(((Student *)a)->name, ((Student *)b)->name);
	if (tmp != 0) return strcmp(((Student *)a)->name, ((Student *)b)->name);
	else return ((Student *)a)->age - ((Student *)b)->age;
}

int main(){
	int n;
	while(scanf("%d", &n)!=EOF){
		Student buf[n];
		for(int i = 0; i < n; i++){
			scanf("%s %d %d", buf[i].name, &buf[i].age, &buf[i].score);
		}
		qsort(buf, n, sizeof(Student), cmp);
		for(int i = 0; i < n; i++){
			printf("%s %d %d\n", buf[i].name, buf[i].age, buf[i].score);
		}
	}
}