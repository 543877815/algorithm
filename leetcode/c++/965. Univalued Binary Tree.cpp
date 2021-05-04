/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 递归
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool find(TreeNode *root, int val) {
        if (!root) return true;
        if (root->val != val) return false;
        return find(root->left, val) && find(root->right, val);
    }

    bool isUnivalTree(TreeNode *root) {
        if (!root) return false;
        return find(root, root->val);
    }
};