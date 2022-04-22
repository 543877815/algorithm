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
class Solution {
public:
    string res;

    void preOrder(TreeNode* root) {
        if (!root) return;
        res += to_string(root->val);
        if (root->left) {
            res += "(";
            preOrder(root->left);
            res += ")";
        }
        if (root->right) {
            if (!root->left) res += "()";
            res += "(";
            preOrder(root->right);
            res += ")";
        }
    }

    string tree2str(TreeNode* root) {
        preOrder(root);
        return res;
    }
};