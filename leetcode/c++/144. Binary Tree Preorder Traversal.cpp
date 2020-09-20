/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *preOrder(struct TreeNode *root, int *arr, int *size) {
    if (root == NULL) return NULL;
    arr[(*size)++] = root->val;
    if (root->left != NULL) preOrder(root->left, arr, size);
    if (root->right != NULL) preOrder(root->right, arr, size);
    return root;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    int *arr = (int *) malloc(sizeof(int) * 100);
    int size = 0;

    preOrder(root, arr, &size);

    *returnSize = size;
    return arr;
}


// c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return {};
        stack < TreeNode * > stack_node;
        stack_node.push(root);
        while (!stack_node.empty()) {
            TreeNode *node = stack_node.top();
            stack_node.pop();
            res.push_back(node->val);
            if (node->right) stack_node.push(node->right);
            if (node->left) stack_node.push(node->left);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack < TreeNode * > stack_node;
        if (root) stack_node.push(root);
        else return {};
        TreeNode *curr;
        while (!stack_node.empty()) {
            curr = stack_node.top();
            stack_node.pop();
            if (curr) {
                if (curr->right) stack_node.push(curr->right);
                if (curr->left) stack_node.push(curr->left);
                stack_node.push(curr);
                stack_node.push(nullptr);
            } else {
                res.push_back(stack_node.top()->val);
                stack_node.pop();
            }
        }
        return res;
    }
};