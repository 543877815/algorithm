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

    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }

    void sumDepth(TreeNode *root, int curr, int depth) {
        if (!root) return;
        curr += 1;
        if (!root->left && !root->right && depth == curr) res += root->val;
        sumDepth(root->left, curr, depth);
        sumDepth(root->right, curr, depth);
    }

    int deepestLeavesSum(TreeNode *root) {
        int depth = maxDepth(root);
        sumDepth(root, 0, depth);
        return res;
    }
};