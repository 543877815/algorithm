/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (!pRoot) return true;
        return SubTree(pRoot->left, pRoot->right);
    }

    bool SubTree(TreeNode *lRoot, TreeNode *rRoot) {
        if (!lRoot && !rRoot) return true;
        if ((!lRoot && rRoot) || (lRoot && !rRoot)) return false;
        if (lRoot->val != rRoot->val) return false;
        return SubTree(lRoot->left, rRoot->right) && SubTree(lRoot->right, rRoot->left);
    }

};