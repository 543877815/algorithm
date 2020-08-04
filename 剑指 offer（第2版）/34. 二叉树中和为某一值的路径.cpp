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
private:
    vector <vector<int>> res;
public:
    vector <vector<int>> pathSum(TreeNode *root, int sum) {
        vector<int> s;
        DFS(root, sum, s);
        return res;
    }

    void DFS(TreeNode *root, int sum, vector<int> &s) {
        if (!root) return;
        s.push_back(root->val);
        if (!root->left && !root->right && sum == root->val) res.push_back(s);
        DFS(root->left, sum - root->val, s);
        DFS(root->right, sum - root->val, s);
        s.pop_back();
    }
};