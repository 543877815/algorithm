// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool res = true;

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        if (abs(leftDepth - rightDepth) > 1) res = false;
        return max(leftDepth, rightDepth) + 1;
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot) return res;
        maxDepth(pRoot);
        return res;
    }
};