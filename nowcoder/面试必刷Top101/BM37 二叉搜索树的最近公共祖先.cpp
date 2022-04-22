/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// 时间复杂度：O(n)
// 空间复杂度：O(h)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param p int整型
     * @param q int整型
     * @return int整型
     */


    int res;

    bool dfs(TreeNode *root, int p, int q) {
        if (!root) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);

        if ((lson && rson) || ((root->val == p || root->val == q) && (lson || rson))) res = root->val;
        return lson || rson || (root->val == p || root->val == q);

    }

    int lowestCommonAncestor(TreeNode *root, int p, int q) {
        // write code here
        dfs(root, p, q);
        return res;
    }
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param p int整型
     * @param q int整型
     * @return int整型
     */




    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        if (!root) return -1;
        if (root->val > p && root->val > q) return lowestCommonAncestor(root->left, p, q);
        if (root->val < p && root->val < q) return lowestCommonAncestor(root->right, p, q);
        return root->val;
    }
};