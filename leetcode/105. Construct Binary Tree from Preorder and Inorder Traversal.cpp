/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode * create() {
    struct TreeNode * T = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    T->left = NULL;
    T->right = NULL;
    return T;
}

struct TreeNode * build(int* pre, int s1, int e1,int *in, int s2, int e2) {
    // printf("%d %d\n", pre[0], in[0]);
    // printf("%d %d %d %d\n", s1, e1, s2, e2);
    struct TreeNode *root = create();
    root->val = pre[s1];
    int rootIndex;
    for (int i = s2; i <= e2; i++) {
        if(pre[s1] == in[i]) {
            rootIndex = i;
            break;
        }
    }
    if (rootIndex != s2) {
        root->left = build(pre, s1+1, s1+rootIndex-s2, in, s2, rootIndex - 1);
    }
    if (rootIndex != e2) {
        root->right = build(pre, s1+rootIndex-s2+1, e1, in, rootIndex+1,e2);
    }
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorderSize==0 || inorderSize == 0) return NULL;
    struct TreeNode *T = build(preorder, 0, preorderSize-1, inorder, 0, inorderSize-1);
    return T;
}

