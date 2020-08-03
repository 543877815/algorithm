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
// 空间复杂度：O(h)
class Solution {
public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root) return 0;
        return sum(root->left, true) + sum(root->right, false);
    }

    int sum(TreeNode *root, bool isLeft) {
        if (!root) return 0;
        if (!root->left && !root->right && isLeft) return root->val;
        return sum(root->left, true) + sum(root->right, false);
    }
};