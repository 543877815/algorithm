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

// 中序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(h)
class Solution {
private:
    void inorder(TreeNode *root, vector<int> &res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

public:
    int kthSmallest(TreeNode *root, int k) {
        vector<int> res;
        inorder(root, res);
        return res[k - 1];
    }
};

// 使用栈实现非递归
// 时间复杂度：O(h+k)
// 空间复杂度：O(h+k)
class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        stack < TreeNode * > s;
        while (true) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (--k == 0) return root->val;
            root = root->right;
        }
    }
};