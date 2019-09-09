#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
	char No[10];
	char name[10];
	char gender[2];
	int age;
} Student;

int main(){
	int num;
	while(scanf("%d", &num) != EOF) {
		Student * students = (Student *)malloc(sizeof(Student) * num);
		for (int i = 0; i < num; i++) {
			scanf("%s %s %s %d", students[i].No, students[i].name, students[i].gender, &students[i].age);
		}
		int num1;
		char *No = (char *)malloc(sizeof(char)*10);
		scanf("%d", &num1);
		for (int i = 0; i < num1; i++) {
			scanf("%s", No);
			int j;
			for (j = 0; j < num; j++) {
				if (strcmp(No, students[j].No) == 0) {
					printf("%s %s %s %d\n", students[j].No, students[j].name, students[j].gender, students[j].age);
					break;
				}
			}
			if (j == num) printf("No Answer!\n");
		}
	}
	return 0;
}