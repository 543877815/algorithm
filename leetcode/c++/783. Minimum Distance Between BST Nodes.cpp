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
// 空间复杂度：O(n)
class Solution {
private:
    int minDis = INT_MAX;
    int last = -1;
public:
    int minDiffInBST(TreeNode *root) {
        if (root->left) minDiffInBST(root->left);
        if (last != -1) minDis = min(minDis, abs(root->val - last));
        last = root->val;
        if (root->right) minDiffInBST(root->right);

        return minDis;
    }
};