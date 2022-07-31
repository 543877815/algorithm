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
// 层序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int maxLevelSum(TreeNode *root) {
        queue < TreeNode * > q;
        q.push(root);
        int max_sum = INT_MIN;
        int res = 0;
        int idx = 0;
        while (!q.empty()) {
            idx++;
            int n = q.size();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode *curr = q.front();
                q.pop();
                sum += curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            if (max_sum < sum) {
                max_sum = max(max_sum, sum);
                res = idx;
            }
        }
        return res;
    }
};