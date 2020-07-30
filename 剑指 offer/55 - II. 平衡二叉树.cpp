/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 先序遍历 + 判断深度
 // 时间复杂度：O(nlogn)
 // 空间复杂度：O(n)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};