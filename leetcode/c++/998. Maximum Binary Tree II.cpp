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
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
        if (!root) return root;
        TreeNode *node = new TreeNode(val);
        if (root->val < val) {
            node->left = root;
            return node;
        }
        TreeNode *last = new TreeNode(-1);
        last->left = root;
        TreeNode *tmp = root;
        while (tmp) {
            if (tmp->val > node->val) {
                last = tmp;
                tmp = tmp->right;
            } else {
                break;
            }
        }
        last->right = node;
        node->left = tmp;

        return root;
    }
};