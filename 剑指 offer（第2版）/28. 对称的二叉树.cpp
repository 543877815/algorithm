/**
* Definition for a binary tree node.
* struct TreeNode {
    *     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
                                                        * };
*/

bool isMirror(TreeNode *t1, TreeNode *t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return isMirror(root, root);
    }
};