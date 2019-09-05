/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int min(int a, int b) {
	return a > b ? b : a;
}

int minDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    if (root->left != NULL && root -> right == NULL) return 1 + minDepth(root->left);
    if (root->left == NULL && root -> right != NULL) return 1 + minDepth(root->right);
    return min(minDepth(root->left) + 1, minDepth(root->right) + 1);
}

