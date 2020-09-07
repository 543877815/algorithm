/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 时间复杂度：O(nh)
// 空间复杂度：O(h)
class Solution {
public:
    int findPath(TreeNode *root, int sum) {
        if (!root) return 0;
        int res = 0;
        if (root->val == sum) res += 1;
        res += findPath(root->left, sum - root->val);
        res += findPath(root->right, sum - root->val);
        return res;
    }

    int pathSum(TreeNode *root, int sum) {
        if (!root) return 0;
        int res = findPath(root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);
        return res;
    }
};