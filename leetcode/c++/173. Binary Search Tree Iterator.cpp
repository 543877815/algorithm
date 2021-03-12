/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(1)

class BSTIterator {
public:
    stack<int> stk;

    void inorder(TreeNode *root) {
        if (!root) return;
        if (root->right) inorder(root->right);
        stk.push(root->val);
        if (root->left) inorder(root->left);
    }

    BSTIterator(TreeNode *root) {
        inorder(root);
    }

    int next() {
        int top = stk.top();
        stk.pop();
        return top;
    }

    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */