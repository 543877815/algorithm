/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 中序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
private:
    vector<int> res;
    int maxCount = 0;
    int count = 0;
    int mode;

    void inorderCount(TreeNode *root) {
        if (!root) return;
        if (root->left) inorderCount(root->left);
        if (mode != root->val) {
            mode = root->val;
            maxCount = max(maxCount, count);
            count = 1;
        } else {
            count++;
        }
        if (root->right) inorderCount(root->right);
    }

    void inorderRecord(TreeNode *root) {
        if (!root) return;
        if (root->left) inorderRecord(root->left);
        if (mode != root->val) {
            if (count == maxCount) res.push_back(mode);
            mode = root->val;
            count = 1;
        } else {
            count++;
        }
        if (root->right) inorderRecord(root->right);
    }

public:
    vector<int> findMode(TreeNode *root) {
        if (!root) return res;
        mode = root->val == INT_MAX ? INT_MIN : INT_MAX;
        inorderCount(root);

        maxCount = max(maxCount, count);
        mode = root->val == INT_MAX ? INT_MIN : INT_MAX;
        count = 0;
        inorderRecord(root);
        if (count == maxCount) res.push_back(mode);
        return res;
    }
};