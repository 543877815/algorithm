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
    int res = INT_MIN;

    int getPathSum(TreeNode *root) {
        if (!root) return 0;
        int leftSum = 0, rightSum = 0;
        if (root->left) leftSum = getPathSum(root->left);
        if (root->right) rightSum = getPathSum(root->right);
        if (root->left && root->right) {
            res = max(res, root->val);
            res = max(res, leftSum);
            res = max(res, rightSum);
            res = max(res, root->val + leftSum);
            res = max(res, root->val + rightSum);
            res = max(res, root->val + leftSum + rightSum);
            return max(max(root->val + leftSum, root->val + rightSum), root->val);
        } else if (root->left) {
            res = max(res, root->val);
            res = max(res, leftSum);
            res = max(res, leftSum + root->val);
            return max(leftSum + root->val, root->val);
        } else if (root->right) {
            res = max(res, root->val);
            res = max(res, rightSum);
            res = max(res, rightSum + root->val);
            return max(rightSum + root->val, root->val);
        } else {
            res = max(res, root->val);
            return root->val;
        }
    }

    int maxPathSum(TreeNode *root) {
        getPathSum(root);
        return res;
    }
};

// 递归+贪心
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