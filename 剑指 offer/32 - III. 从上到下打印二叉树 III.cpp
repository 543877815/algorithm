/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 标准层次遍历后奇偶翻转
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector<int>> res;
        if (!root) return res;
        int level;
        queue <pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode *node = q.front().first;
            level = q.front().second;
            q.pop();

            if (level == res.size())
                res.push_back(vector<int>());
            res[level].push_back(node->val);
            if (node->left) q.push(make_pair(node->left, level + 1));
            if (node->right) q.push(make_pair(node->right, level + 1));
        }
        for (int i = 1; i <= level; i += 2) {
            reverse(res[i].begin(), res[i].end());
        }

        return res;
    }
};