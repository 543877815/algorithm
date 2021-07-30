/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 层次遍历 + 递归
// 时间复杂度：O(n)
// 空间复杂度：O(logn)
class Solution {
public:
    vector<int> res;

    // 层次遍历
    void find(TreeNode *root, int k) {
        if (!root) return;
        if (k < 0) return;

        queue < TreeNode * > q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *curr = q.front();
                int val = curr->val;
                q.pop();
                if (k == 0) res.push_back(val);
                else {
                    if (curr->left) q.push(curr->left);
                    if (curr->right) q.push(curr->right);
                }
            }
            k--;
        }
    }

    int getDis(TreeNode *root, TreeNode *target, int k) {
        if (root == target) return 1;
        if (!root) return -1;

        int leftDepth = getDis(root->left, target, k);
        int rightDepth = getDis(root->right, target, k);

        if (leftDepth != -1) {
            if (leftDepth == k) res.push_back(root->val);
            find(root->right, k - leftDepth - 1);
        }
        if (rightDepth != -1) {
            if (rightDepth == k) res.push_back(root->val);
            find(root->left, k - rightDepth - 1);
        }

        if (leftDepth != -1) return leftDepth + 1;
        else if (rightDepth != -1) return rightDepth + 1;
        else return -1;

    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        find(target, k);
        getDis(root, target, k);
        return res;
    }
};