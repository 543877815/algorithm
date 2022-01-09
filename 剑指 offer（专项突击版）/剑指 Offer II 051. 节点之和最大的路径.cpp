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
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int res = INT_MIN;

    int maxGain(TreeNode *root) {
        if (!root) return 0;

        int leftSum = max(maxGain(root->left), 0);
        int rightSum = max(maxGain(root->right), 0);

        int priceNewPath = root->val + leftSum + rightSum;

        res = max(res, priceNewPath);

        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode *root) {
        maxGain(root);
        return res;
    }
};