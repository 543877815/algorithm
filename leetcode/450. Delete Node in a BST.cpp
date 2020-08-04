/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 时间复杂度：O(h)
// 空间复杂度：O(1)
class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) return NULL;
        // 整一个dummy节点统一操作
        TreeNode *dummynode = new TreeNode(INT_MAX);
        dummynode->left = root;

        TreeNode *parent = dummynode;
        TreeNode *curr = root;

        // 找到 key 节点
        while (curr && curr->val != key) {
            parent = curr;
            if (curr->val > key) {
                curr = curr->left;
            } else if (curr->val < key) {
                curr = curr->right;
            }
        }
        if (!curr) return root;

        // 删除
        if (parent->val > key) {
            if (curr->right) {
                parent->left = curr->right;
                TreeNode *tmp = curr->right;
                while (tmp && tmp->left) {
                    tmp = tmp->left;
                }
                tmp->left = curr->left;
            } else {
                parent->left = curr->left;
            }
            delete curr;
        } else {
            if (curr->left) {
                parent->right = curr->left;
                TreeNode *tmp = curr->left;
                while (tmp && tmp->right) {
                    tmp = tmp->right;
                }
                tmp->right = curr->right;
            } else {
                parent->right = curr->right;
            }
            delete curr;
        }
        return dummynode->left;
    }
};