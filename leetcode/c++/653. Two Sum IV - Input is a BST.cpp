/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 使用set
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    unordered_set<int> myset;
    int k;

    bool preorder(TreeNode *root) {
        if (!root) return false;
        if (myset.find(k - root->val) != myset.end()) return true;
        myset.insert(root->val);
        return preorder(root->left) || preorder(root->right);
    }

    bool findTarget(TreeNode *root, int k) {
        this->k = k;
        return preorder(root);
    }
};