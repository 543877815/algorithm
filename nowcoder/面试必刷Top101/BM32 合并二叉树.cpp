/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

// 时间复杂度：O(n)
// 空间复杂度：O(h)
class Solution {
public:
    /**
     *
     * @param t1 TreeNode类
     * @param t2 TreeNode类
     * @return TreeNode类
     */
    void merge(TreeNode *t1, TreeNode *t2) {
        if (t1 && t2) t1->val += t2->val;
        if (t1->left && t2->left) merge(t1->left, t2->left);
        if (t1->right && t2->right) merge(t1->right, t2->right);
        if (!t1->left && t2->left) t1->left = t2->left;
        if (!t1->right && t2->right) t1->right = t2->right;
    }

    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        merge(t1, t2);
        return t1;
    }
};