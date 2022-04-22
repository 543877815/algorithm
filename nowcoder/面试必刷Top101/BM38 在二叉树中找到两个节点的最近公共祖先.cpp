/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    int res;

    bool dfs(TreeNode *root, int o1, int o2) {
        if (!root) return false;
        bool lson = dfs(root->left, o1, o2);
        bool rson = dfs(root->right, o1, o2);
        if ((lson && rson) || ((lson || rson) && (root->val == o1 || root->val == o2))) res = root->val;

        return lson || rson || root->val == o1 || root->val == o2;
    }

    int lowestCommonAncestor(TreeNode *root, int o1, int o2) {
        // write code here

        dfs(root, o1, o2);
        return res;
    }
};