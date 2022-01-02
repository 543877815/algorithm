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
bool deleteNode(TreeNode *root) {
    if (!root) return false;
    if (deleteNode(root->left)) root->left = nullptr;
    if (deleteNode(root->right)) root->right = nullptr;
    if (root->val == 0 && !root->left && !root->right) return true;
    return false;
}

class Solution {
public:
    TreeNode *pruneTree(TreeNode *root) {
        TreeNode *dummyroot = new TreeNode(-1, root, nullptr);
        deleteNode(dummyroot);
        return dummyroot->left;
    }
};