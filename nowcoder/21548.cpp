
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    Node *next;
    int val;
};

Node * create(){
    Node* T = (Node*)malloc(sizeof(Node));
    T->next = NULL;
    return T;
}

void Insert(Node *T, int val) {
    Node *p = T->next;
    Node *pre = T;
    while(p) {
        if (p->val < val){
            pre = p;
            p = p->next;
        } else break;
    }
    Node *q = create();
    q->val = val;
    pre->next = q;
    q->next = p;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        Node * T = create();
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            Insert(T, x);
        }
        while(T->next){
            T = T->next;
            printf("%d ", T->val);
        }
    }
    return 0;
}