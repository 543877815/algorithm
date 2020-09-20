/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root) return NULL;

        if (!root->left && !root->right) return root;

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        if (root->left) invertTree(root->left);
        if (root->right) invertTree(root->right);

        return root;
    }
};