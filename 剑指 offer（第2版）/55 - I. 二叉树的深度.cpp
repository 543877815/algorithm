/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 递归
// 时间复杂度：O(n)
// 空间复杂度：O(height)
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// 广度优先搜索
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        int res = 0;
        record.push(make_pair(root, 1));
        while (!record.empty()) {
            TreeNode *curr = record.front().first;
            int level = record.front().second;
            record.pop();
            res = max(res, level);
            if (curr->left) record.push(make_pair(curr->left, level + 1));
            if (curr->right) record.push(make_pair(curr->right, level + 1));
        }
        return res;
    }
};