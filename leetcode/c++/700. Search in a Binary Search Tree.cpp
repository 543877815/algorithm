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
// 时间复杂度：O(H)
// 空间复杂度：O(1)
class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        if (!root) return NULL;
        if (val == root->val) {
            return root;
        } else if (val > root->val) {
            return searchBST(root->right, val);
        } else if (val < root->val) {
            return searchBST(root->left, val);
        }

        return NULL;
    }
};