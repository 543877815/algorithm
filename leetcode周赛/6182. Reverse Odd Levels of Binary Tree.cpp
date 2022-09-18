// 时间复杂度：O(n)
// 空间复杂度：O(n)
// 层次遍历
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;
        queue<pair<TreeNode*, int>> q;
        int curr_level = 0;
        q.push(make_pair(root, curr_level));
        vector<int> tmp;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto top = q.front();
                q.pop();
                TreeNode *node = top.first;
                curr_level = top.second;

                if (curr_level % 2 == 1) {
                    node->val = tmp[n - 1 - i];
                }
                if (node->left) {
                    q.push(make_pair(node->left, curr_level+1));
                    tmp.push_back(node->left->val);
                }
                if (node->right) {
                    q.push(make_pair(node->right, curr_level+1));
                    tmp.push_back(node->right->val);
                }
            }
            if (curr_level % 2 == 1) tmp.resize(0);
        }

        return root;
    }
};