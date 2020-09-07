/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    bool checkSubTree(TreeNode *t1, TreeNode *t2) {
        if (t1 == NULL && t2 == NULL) return true;
        if (t2 != NULL && t1 == NULL) return false;
        if (t1 != NULL && t2 == NULL) return true;
        if (t1->val != t2->val) {
            return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
        } else {
            return checkSubTree(t1->left, t2->left) && checkSubTree(t1->right, t2->right);
        }
    }
};