/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MaxSize 760

void LevelOrder(struct TreeNode * TreeRoot, int **ans, int level, int* index) {
    if(TreeRoot != NULL){
        ans[level][index[level]] = TreeRoot->val;
        index[level] ++;
    }
    
    if(TreeRoot->left != NULL) {
        LevelOrder(TreeRoot->left, ans, level + 1, index);
    }
    
    if(TreeRoot->right != NULL) {
        LevelOrder(TreeRoot->right, ans, level + 1, index);
    }
}


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(!root) {
        * returnSize = 0;
        return root;
    }
    int num = MaxSize;
    int **ans = (int **)malloc(sizeof(int*)*num);
    for (int i = 0; i < num; i++) {
        ans[i] = (int *)malloc(sizeof(int)*num);
    }
    
    int size = 0;
    int *index = (int *)malloc(sizeof(int)*num);
    for (int i = 0; i < num; i++) {
        index[i] = 0;
    }
    LevelOrder(root, ans, 0, index);
    
    for (int i = 0; i < num; i++) {
        if(index[i] == 0) {
            size = i;
            break;
        }
    }
    
    *returnSize = size;
    *returnColumnSizes = (int *)malloc(sizeof(int)*(size));
    for(int i = 0; i < size; i++){
        (*returnColumnSizes)[i] = index[i];
    }
    return ans;
}