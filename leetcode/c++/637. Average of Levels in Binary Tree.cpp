/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MaxSize 760

int max(int a, int b) {
    return a > b ? a : b;
}

int maxDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}


void LevelOrder(struct TreeNode * TreeRoot, double *ans, int level, int* num) {
    if(TreeRoot != NULL){
        ans[level] += (double) TreeRoot->val;
        num[level] ++;
    }
    
    if(TreeRoot->left != NULL) {
        LevelOrder(TreeRoot->left, ans, level + 1, num);
    }
    
    if(TreeRoot->right != NULL) {
        LevelOrder(TreeRoot->right, ans, level + 1, num);
    }
}


double* averageOfLevels(struct TreeNode* root, int* returnSize){
    if(!root) {
        *returnSize = 0;
        return root;
    }
    int maxdepth = maxDepth(root);
    double *ans = (double *)malloc(sizeof(double)*maxdepth);
    int *num = (int *)malloc(sizeof(int)*maxdepth);
    for (int i = 0; i < maxdepth; i++) {
        ans[i] = 0;
        num[i] = 0;
    }
    

    LevelOrder(root, ans, 0, num);
    
    for (int i = 0; i < maxdepth; i++) {
        ans[i] = ans[i] / num[i];
    }
    *returnSize = maxdepth;
    return ans;
}

