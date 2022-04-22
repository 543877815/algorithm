/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return bool布尔型
     */
    bool res = true;
    TreeNode *prev = nullptr;

    void inorder(TreeNode *root) {
        if (!root) return;
        if (root->left) inorder(root->left);
        if (prev && prev->val >= root->val) {
            res = false;
            return;
        }
        prev = root;
        if (root->right) inorder(root->right);
    }

    bool isValidBST(TreeNode *root) {
        // write code here
        inorder(root);
        return res;
    }
};