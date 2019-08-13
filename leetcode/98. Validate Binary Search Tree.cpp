/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode * inOrder(struct TreeNode* root, int* arr, int *size) {
    if(root == NULL) return NULL;
    if(root->left!=NULL) inOrder(root->left, arr, size);
    arr[(*size)++] = root->val;
    if(root->right!=NULL) inOrder(root->right, arr, size);
    return root;
}

bool isValidBST(struct TreeNode* root){
    if(root == NULL) return true;
    int *arr = (int*) malloc (sizeof(int) * 20000);
    int size = 0;
    
    inOrder(root, arr, &size);

    for(int i = 0; i < size - 1; i++) {
        if(arr[i] >= arr[i+1]) return false;
    }
    return true;
    
}

