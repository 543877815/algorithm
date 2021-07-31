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
 **/
// 深度优先遍历
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    vector <tuple<int, int, int>> nodes;
    vector <vector<int>> res;

    void preorder(TreeNode *root, int row, int col) {
        if (!root) return;
        nodes.emplace_back(col, row, root->val);
        preorder(root->left, row + 1, col - 1);
        preorder(root->right, row + 1, col + 1);
    }

    vector <vector<int>> verticalTraversal(TreeNode *root) {
        preorder(root, 0, 0);
        sort(nodes.begin(), nodes.end());
        int lastcol
        INT_MIN;
        for (const auto&[col, row, val] : nodes) {
            if (col != lastcol) {
                lastcol = col;
                res.push_back({});
            }
            res.back().push_back(val);
        }

        return res;
    }
};
