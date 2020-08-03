/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> record;
        record.push(root);
        while(!record.empty()) {
            TreeNode *curr = record.front();
            record.pop();
            res.push_back(curr->val);
            if (curr->left) record.push(curr->left);
            if (curr->right) record.push(curr->right);
        }
        return res;
    }
};