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
// 时间复杂度：O(n)
// 空间复杂度：O(logn)
class Solution {
public:
    int sum = 0;

    void preorder(TreeNode *root, int presum) {
        if (!root) return;
        presum = presum * 10 + root->val;
        if (!root->left && !root->right) sum += presum;
        if (root->left) preorder(root->left, presum);
        if (root->right) preorder(root->right, presum);
    }

    int sumNumbers(TreeNode *root) {
        preorder(root, 0);
        return sum;
    }
};