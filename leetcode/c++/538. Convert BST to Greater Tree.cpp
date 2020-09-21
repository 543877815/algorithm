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
private:
    int sum = 0;
public:
    void greater(TreeNode *root) {
        if (root->right) greater(root->right);
        int tmp = root->val;
        root->val += sum;
        sum += tmp;
        if (root->left) greater(root->left);

    }

    TreeNode *convertBST(TreeNode *root) {
        if (!root) return root;
        greater(root);
        return root;
    }
};