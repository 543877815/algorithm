#include <stdio.h>
#include <stdlib.h>

struct Node {
    Node *lchild;
    Node *rchild;
    int val;
};

Node * create(){
    Node * T = (Node *)malloc(sizeof(Node));
    T->lchild = T->rchild = NULL;
    return T;
}

Node * Insert(Node * root, int val){
    if(root == NULL){
        root = create();
        root->val = val;
        return root;
    } else if (root->val < val) {
        if(root->rchild == NULL) {
            printf("%d\n", root->val);
        }
        root->rchild = Insert(root->rchild, val);
    } else if (root->val > val) {
        if(root->lchild == NULL) {
            printf("%d\n", root->val);
        }
        root->lchild = Insert(root->lchild, val);
    }
    return root;
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF) {
        Node *T = NULL;
        for (int i = 0; i < n; i++) {
            int x ;
            scanf("%d", &x);
            if(T == NULL) {
                printf("-1\n");
            }
            T = Insert(T, x);
        }
    }
    
    return 0;
}