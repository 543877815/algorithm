/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 递归
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int res = 0;

    int find(TreeNode *root) {
        if (!root) return 0;
        int left = 0, right = 0;
        if (root->left) left = find(root->left) + 1;
        if (root->right) right = find(root->right) + 1;
        res = max(res, left + right);
        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode *root) {
        find(root);
        return res;
    }
};