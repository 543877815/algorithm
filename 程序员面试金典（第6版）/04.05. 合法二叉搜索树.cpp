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
 // 空间复杂度：O(n)
class Solution {
private:
    long long pre = -2147483648 - 1;

public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        bool valid = isValidBST(root->left);
        if (root->val <= pre) return false;
        pre = root->val;
        valid &= isValidBST(root->right);
        return valid;
    }
};