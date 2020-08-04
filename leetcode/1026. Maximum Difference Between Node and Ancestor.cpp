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
 // 空间复杂度：O(h)
class Solution {
public:
    int DFS(TreeNode *root, stack <pair<int, int>> &s) {
        if (!root) return 0;
        int min_v = min(s.top().first, root->val);
        int max_v = max(s.top().second, root->val);
        s.push(make_pair(min_v, max_v));
        int dis_l = DFS(root->left, s);
        int dis_r = DFS(root->right, s);
        int dis = max(dis_l, dis_r);
        s.pop();
        return max(dis, abs(min_v - max_v));
    }

    int maxAncestorDiff(TreeNode *root) {
        int min_v = INT_MAX, max_v = INT_MIN;
        stack <pair<int, int>> s;
        s.push(make_pair(min_v, max_v));
        return DFS(root, s);
    }
};