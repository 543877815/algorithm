// 深度优先搜索
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
private:
    int res;

public:
    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }

    int dfs(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left), right = dfs(root->right);
        int left1 = 0, right1 = 0;
        if (root->left && root->left->val == root->val) {
            left1 = left + 1;
        }
        if (root->right && root->right->val == root->val) {
            right1 = right + 1;
        }
        res = max(res, left1 + right1);
        return max(left1, right1);
    }
};