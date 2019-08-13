/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b) {
    return a > b ? a : b;
}

void postOrder(struct TreeNode* root){
    if (root == NULL) return;
    if (root -> left != NULL) postOrder(root->left);
    if (root -> right != NULL) postOrder(root->right);
    
    int root_node = root->val;
    int node = 0;
    if (root->left != NULL) {
        node += root->left->val;
        if (root->left->left != NULL) {
            root_node += root->left->left->val;
        }
        if (root->left->right != NULL) {
            root_node += root->left->right->val;
        }
    }
    if (root->right != NULL) {
        node += root->right->val;
        if (root->right->left != NULL) {
            root_node += root->right->left->val;
        }
        if (root->right->right != NULL) {
            root_node += root->right->right->val;
        }
    }
    root->val = max(root_node, node);
}


int rob(struct TreeNode* root){
    if (root == NULL) return 0;
    postOrder(root);
    return root->val;
}

