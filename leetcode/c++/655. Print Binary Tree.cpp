/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 队列
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
private:
    int getTreeHeight(TreeNode *root) {
        if (!root) return 0;
        return max(getTreeHeight(root->left), getTreeHeight(root->right)) + 1;
    }
public:
    vector <vector<string>> printTree(TreeNode *root) {
        int row = getTreeHeight(root);
        int col = ((int) pow(2, row)) - 1;
        vector <vector<string>> res = vector < vector < string >> (row, vector<string>(col, ""));
        if (!root) return res;
        int middle = col / 2;
        queue < pair < TreeNode * , pair < int, int>>> q;
        q.push(make_pair(root, make_pair(0, middle)));
        int lastLayer = -1;
        while (!q.empty()) {
            auto[curr, position] = q.front();
            auto[layer, index] = position;
            q.pop();
            res[layer][index] = to_string(curr->val);
            if (lastLayer != layer) {
                middle = (middle + 1) / 2;
                lastLayer = layer;
            }
            if (curr->left) q.push(make_pair(curr->left, make_pair(layer + 1, index - middle)));
            if (curr->right) q.push(make_pair(curr->right, make_pair(layer + 1, index + middle)));
        }

        return res;
    }
};