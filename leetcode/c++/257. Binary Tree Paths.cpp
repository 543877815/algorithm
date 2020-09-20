/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 使用递归
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector <string> binaryTreePaths(TreeNode *root) {
        vector <string> res;
        if (!root) return res;
        if (!root->left && !root->right) res.push_back(to_string(root->val));
        getPaths(root->left, res, to_string(root->val));
        getPaths(root->right, res, to_string(root->val));
        return res;
    }

    void getPaths(TreeNode *root, vector <string> &res, string route) {
        if (!root) return;

        route = route + "->" + to_string(root->val);

        if (!root->left && !root->right && route.size()) {
            res.push_back(route);
            return;
        }
        getPaths(root->left, res, route);
        getPaths(root->right, res, route);
    }
};

// 使用递归
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        if (!root->left && !root->right) {
            res.push_back(to_string(root->val));
            return res;
        }
        vector<string> leftS = binaryTreePaths(root->left);
        for (int i = 0; i < leftS.size(); i++)
        res.push_back(to_string(root->val) + "->" + leftS[i]);

        vector<string> rightS = binaryTreePaths(root->right);
        for (int i = 0; i < rightS.size(); i++)
            res.push_back(to_string(root->val) + "->" + rightS[i]);

        return res;
    }
};