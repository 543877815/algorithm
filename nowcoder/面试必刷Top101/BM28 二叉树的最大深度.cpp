/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
// 递归
// 时间复杂度：O(n)
// 空间复杂度：O(h)
class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @return int整型
     */
    int maxDepth(TreeNode* root) {
        // write code here
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};