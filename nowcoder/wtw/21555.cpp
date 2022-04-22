#include<stdio.h>
#include<stdlib.h>

struct Node {
    Node *left;
    Node *right;
    int val;
};

Node *create(){
    Node *T = (Node *)malloc(sizeof(Node));
    T->left = T->right = NULL;
    return T;
}

Node* Insert(Node*root, int val){
    if(root == NULL) {
        root = create();
        root->val = val;
        return root;
    } else if (root->val<val) {
        root->right = Insert(root->right, val);
    } else if (root->val>val) {
        root->left = Insert(root->left, val);
    }
    return root;
}

void postOrder(Node*root){
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
}

void inOrder(Node*root){
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}

void preOrder(Node*root){
    if (root == NULL) return;
    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    int n; 
    while(scanf("%d", &n) != EOF) {
        Node * T = NULL;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            T = Insert(T, x);
        }
        preOrder(T);
        printf("\n");
        inOrder(T);
        printf("\n");
        postOrder(T);
        printf("\n");
        
    }
    return 0;
}