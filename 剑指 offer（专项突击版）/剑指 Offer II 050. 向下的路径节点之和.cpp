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
// 双递归
// 时间复杂度：O(n^2)
// 空间复杂度：O(h)
class Solution {
public:
    int preorder(TreeNode *root, int sum) {
        if (!root) return 0;
        int res = 0;
        if (root->val == sum) res++;
        res += preorder(root->left, sum - root->val);
        res += preorder(root->right, sum - root->val);

        return res;
    }

    int pathSum(TreeNode *root, int targetSum) {
        if (!root) return 0;
        int res = preorder(root, targetSum);
        res += pathSum(root->left, targetSum);
        res += pathSum(root->right, targetSum);
        return res;
    }
};