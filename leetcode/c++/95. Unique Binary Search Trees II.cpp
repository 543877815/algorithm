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
// 时间复杂度：O(2^n)
// 时间复杂度：O(2^n)
class Solution {
public:
    vector<TreeNode *> backtrack(int left, int right) {
        vector < TreeNode * > res;
        if (left > right) {
            res.push_back(nullptr);
            return res;
        }

        for (int i = left; i <= right; i++) {
            vector < TreeNode * > leftNodes = backtrack(left, i - 1);
            vector < TreeNode * > rightNodes = backtrack(i + 1, right);
            for (TreeNode *leftNode: leftNodes) {
                for (TreeNode *rightNode: rightNodes) {
                    TreeNode *root = new TreeNode(i, leftNode, rightNode);
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return vector<TreeNode *>();
        return backtrack(1, n);
    }
};