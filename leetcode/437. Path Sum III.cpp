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
 // 时间复杂度：O(n^2)
 // 空间复杂度：O(h)
class Solution {
private:
    int findPath(TreeNode *node, int num) {
        if (!node) return 0;
        int res = 0;
        if (node->val == num) res += 1;
        res += findPath(node->left, num - node->val);
        res += findPath(node->right, num - node->val);
        return res;
    }

public:
    int pathSum(TreeNode *root, int sum) {
        if (!root) return 0;
        int res = findPath(root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);
        return res;
    }
};