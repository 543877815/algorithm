/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return TreeNode类
     */
    void change(TreeNode* root) {
        if (!root) return;
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        change(root->left);
        change(root->right);
    }

    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        change(pRoot);
        return pRoot;
    }
};