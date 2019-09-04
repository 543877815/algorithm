#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	struct Node* lchild;
	struct Node* rchild;
	char c;
} Node;

Node * create(){
	Node * T = (Node*)malloc(sizeof(Node));
	T->lchild = NULL;
	T->rchild = NULL;
	return T; 
}

void inOrder(Node * T){
	if (T->lchild != NULL) inOrder(T->lchild);
	printf("%c ", T->c);
	if (T->rchild != NULL) inOrder(T->rchild);
}

char string[101];
int length;
int pos;

Node * BuildTree() {
	if(pos >= length)  return NULL;
	if(string[pos]=='#'){
		pos++;
		return NULL;
	} 
	Node *p = create();
	p->c = string[pos++];
	p->lchild = BuildTree();
	p->rchild = BuildTree();
	return p;
}

int main(){
    while(scanf("%s", string) != EOF) {
		length = strlen(string);
		pos = 0;
		Node *T = BuildTree();
		inOrder(T);
		printf("\n");
    }
    return 0;
}