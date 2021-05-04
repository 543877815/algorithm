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
// 用数组存一下
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<TreeNode *> record;

    void inOrderTraverse(TreeNode *root) {
        if (!root) return;
        if (root->left) inOrderTraverse(root->left);
        record.push_back(root);
        if (root->right) inOrderTraverse(root->right);
    }

    TreeNode *increasingBST(TreeNode *root) {
        inOrderTraverse(root);
        int n = record.size();
        for (int i = 0; i < n - 1; i++) {
            record[i]->left = NULL;
            record[i]->right = record[i + 1];
        }
        record[n - 1]->left = record[n - 1]->right = NULL;
        return record[0];
    }
};

// 在遍历中修改节点
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    TreeNode *pre;
    TreeNode *head;

    void inOrderTraverse(TreeNode *root) {
        if (!root) return;
        if (root->left) inOrderTraverse(root->left);
        root->left = NULL;
        if (!head) {
            head = root;
            pre = root;
        } else {
            pre->right = root;
            pre = root;
        }
        if (root->right) inOrderTraverse(root->right);
    }

    TreeNode *increasingBST(TreeNode *root) {
        inOrderTraverse(root);
        return head;
    }
};