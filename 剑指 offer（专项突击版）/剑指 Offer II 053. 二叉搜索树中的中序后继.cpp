/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 中序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    TreeNode *pre;
    TreeNode *res;

    void inorder(TreeNode *root, TreeNode *p) {
        if (!root) return;
        if (root->left) inorder(root->left, p);
        if (pre == p) res = root;
        pre = root;
        if (root->right) inorder(root->right, p);
    }

    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        inorder(root, p);
        return res;
    }
};