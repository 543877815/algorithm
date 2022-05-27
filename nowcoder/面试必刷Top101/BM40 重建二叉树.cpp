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
    // 快速定位根节点
    unordered_map<int, int> index;
    TreeNode* build(vector<int>& preorder, int s1, int e1, vector<int>& inorder, int s2, int e2) {
        if (s1 > e1 || s2 > e2) return nullptr;
        TreeNode* node = new TreeNode(preorder[s1]); // 创建根节点
        int idx = index[preorder[s1]]; // 获取根节点在inorder中的位置
        int size_left_subtree = idx - s2; // 获取左子树个数
        node->left = build(preorder, s1 + 1, s1 + size_left_subtree, inorder, s2, idx-1);
        node->right = build(preorder, s1 + size_left_subtree + 1, e1, inorder, idx + 1, e2);
        return node;
    }

    TreeNode* reConstructBinaryTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return build(preorder, 0, n-1, inorder, 0, n-1);
    }
};