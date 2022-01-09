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
// 中序遍历(数组/栈)
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class BSTIterator {
public:
    TreeNode *curr;
    vector<TreeNode *> recorder;
    int index;

    void inorder(TreeNode *root) {
        if (!root) return;

        inorder(root->left);
        recorder.push_back(root);
        inorder(root->right);
    }

    BSTIterator(TreeNode *root) {
        curr = new TreeNode(INT_MIN);
        recorder.push_back(curr);
        inorder(root);
        index = 0;
    }

    int next() {
        return recorder[++index]->val;
    }

    bool hasNext() {
        return index < recorder.size() - 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */