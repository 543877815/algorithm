/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode * preOrder(struct TreeNode* root, int* arr, int *size) {
    if(root == NULL) return NULL;
    arr[(*size)++] = root->val;
    if(root->left!=NULL) preOrder(root->left, arr, size);
    if(root->right!=NULL) preOrder(root->right, arr, size);
    return root;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *arr = (int*) malloc (sizeof(int) * 100);
    int size = 0;
    
    preOrder(root, arr, &size);

    * returnSize = size;
    return arr;
}

