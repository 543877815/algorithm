/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode * postOrder(struct TreeNode* root, int* arr, int *size) {
    if(root == NULL) return NULL;
    if(root->left!=NULL) postOrder(root->left, arr, size);
    if(root->right!=NULL) postOrder(root->right, arr, size);
    arr[(*size)++] = root->val;
    return root;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *arr = (int*) malloc (sizeof(int) * 100);
    int size = 0;
    
    postOrder(root, arr, &size);

    * returnSize = size;
    return arr;
}

