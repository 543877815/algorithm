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
// 层次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        queue < TreeNode * > q;
        int res = root->val;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                if (i == 0) res = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }
        }
        return res;

    }
};