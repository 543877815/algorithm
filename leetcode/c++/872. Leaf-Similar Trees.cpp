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
// 递归
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    void getLeaf(vector<int> &leaf, TreeNode *root) {
        if (!root) return;
        if (!root->left && !root->right) leaf.push_back(root->val);
        if (root->left) getLeaf(leaf, root->left);
        if (root->right) getLeaf(leaf, root->right);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        getLeaf(leaf1, root1);
        getLeaf(leaf2, root2);

        int n = leaf1.size(), m = leaf2.size();
        if (n != m) return false;
        for (int i = 0; i < n; i++) {
            if (leaf1[i] != leaf2[i]) return false;
        }

        return true;
    }
};