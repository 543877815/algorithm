/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode * create(){
    struct TreeNode * T = (struct TreeNode *) malloc (sizeof(struct TreeNode));
    T->left = NULL;
    T->right = NULL;
    return T;
}

struct TreeNode* build(int* inorder, int s1, int e1, int *postorder, int s2, int e2) {
    struct TreeNode * root = create();
    root->val = postorder[e2];
    int rootIndex;
    for (int i = 0 ; i <= e1; i++) {
        if (inorder[i] == postorder[e2]) {
            rootIndex = i;
            break;
        }
    }
    // printf("%d %d %d %d %d\n", s1, e1, s2, e2, rootIndex);
    if (rootIndex != s1) {
        root->left = build(inorder, s1, rootIndex - 1, postorder, s2, e2-(e1-rootIndex) - 1);
    } 
    if (rootIndex != e1) {
        root->right = build(inorder, rootIndex + 1, e1, postorder, e2-(e1-rootIndex), e2 - 1)  ;  
    }
    
    
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if(inorderSize == 0 || postorderSize == 0) return NULL;
    struct TreeNode * T = build(inorder, 0, inorderSize-1, postorder, 0, postorderSize-1);
    return T;
}

