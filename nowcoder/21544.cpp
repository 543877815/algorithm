#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[27];
char str2[27];

struct Node {
    Node *lchild;
    Node *rchild;
    char word;
};

Node* create(){
    Node * T = (Node *)malloc(sizeof(Node));
    T->lchild = T->rchild = NULL;
    return T;
}

void postOrder(Node *root) {
    if(root == NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%c", root->word);
}

Node * build(int s1, int e1, int s2, int e2){
    Node *ret = create();
    ret->word = str1[s1];
    int rootIndex;
    for (int i = s2; i <= e2; i++) {
        if (str2[i] == str1[s1]) {
            rootIndex = i;
            break;
        }
    }
    if (rootIndex != s2) {
        ret->lchild = build(s1+1,s1+rootIndex-s2,s2,rootIndex-1);
    }
    if (rootIndex != e2) {
        ret->rchild = build(s1+rootIndex-s2+1, e1, rootIndex+1, e2);
    }
    return ret;
}

int main(){
    while(scanf("%s", str1) != EOF) { // 前序队列
        scanf("%s", str2); // 中序队列
        int length1 = strlen(str1);
        int length2 = strlen(str2);
        Node * T = build(0, length1 - 1, 0, length2 - 1);
        postOrder(T); 
		printf("\n"); 
    }
    
    return 0;
}