// 层次遍历，广度优先搜索
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        queue <pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode *node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level == res.size())
                res.push_back(0);
            res[level] = node->val;
            if (node->left) q.push(make_pair(node->left, level + 1));
            if (node->right) q.push(make_pair(node->right, level + 1));
        }
        return res;
    }
};