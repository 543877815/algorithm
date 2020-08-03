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
//// 空间复杂度：O(n)
class Solution {
public:
    TreeNode *mirrorTree(TreeNode *root) {
        if (!root) return NULL;

        if (!root->left && !root->right) return root;

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        if (root->left) mirrorTree(root->left);
        if (root->right) mirrorTree(root->right);

        return root;
    }
};