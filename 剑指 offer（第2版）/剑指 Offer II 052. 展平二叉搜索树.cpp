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

// 中序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    TreeNode *pre;
    TreeNode *head;

    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        root->left = nullptr;
        if (!head) {
            head = root;
            pre = root;
        } else {
            pre->right = root;
            pre = root;
        }


        inorder(root->right);
    }

    TreeNode *increasingBST(TreeNode *root) {
        inorder(root);
        return head;
    }
};