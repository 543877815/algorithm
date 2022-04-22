/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
// 时间复杂度：O(n)
// 空间复杂度：O(h)
class Solution {
public:
    TreeNode *prev;
    void inOrder(TreeNode* root) {
        if (!root) return;
        if (root->left) inOrder(root->left);
        root->left = prev;
        if (prev) prev->right = root;
        prev = root;
        if (root->right) inOrder(root->right);
    }

    TreeNode* Convert(TreeNode* pRootOfTree) {
        prev = nullptr;
        inOrder(pRootOfTree);
        TreeNode* tmp = prev;
        while (tmp && tmp->left) tmp = tmp->left;
        return tmp;
    }
};
