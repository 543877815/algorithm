
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
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector <vector<int>> res;

    void preOrder(TreeNode *root, vector<int> &tmp) {
        if (!root) return;
        tmp.push_back(root->val);
        preOrder(root->left, tmp);
        preOrder(root->right, tmp);
    }

    void inOrder(TreeNode *root, vector<int> &tmp) {
        if (!root) return;
        inOrder(root->left, tmp);
        tmp.push_back(root->val);
        inOrder(root->right, tmp);
    }

    void postOrder(TreeNode *root, vector<int> &tmp) {
        if (!root) return;
        postOrder(root->left, tmp);
        postOrder(root->right, tmp);
        tmp.push_back(root->val);
    }

    vector <vector<int>> threeOrders(TreeNode *root) {
        // write code here
        vector <vector<int>> res;
        vector<int> tmp;
        preOrder(root, tmp);
        res.push_back(tmp);

        tmp.clear();
        inOrder(root, tmp);
        res.push_back(tmp);

        tmp.clear();
        postOrder(root, tmp);
        res.push_back(tmp);

        return res;
    }
};