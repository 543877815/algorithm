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

// 反向中序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    void verseInorder(TreeNode *root, int &sum) {
        if (!root) return;
        verseInorder(root->right, sum);
        sum += root->val;
        root->val = sum;
        verseInorder(root->left, sum);
    }

    TreeNode *convertBST(TreeNode *root) {
        int sum = 0;
        verseInorder(root, sum);
        return root;
    }
};