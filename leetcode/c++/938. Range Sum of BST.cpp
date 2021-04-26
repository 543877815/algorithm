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

// 深度优先搜索
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int sum = 0;

    void inOrderTraverse(TreeNode *root, int &low, int &high) {
        if (!root) return;
        if (root->left && root->val > low) inOrderTraverse(root->left, low, high);
        if (root->right && root->val < high) inOrderTraverse(root->right, low, high);
        if (low <= root->val && root->val <= high) sum += root->val;
    }

    int rangeSumBST(TreeNode *root, int low, int high) {
        inOrderTraverse(root, low, high);
        return sum;
    }
};