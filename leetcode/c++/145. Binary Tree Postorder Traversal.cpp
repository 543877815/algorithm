/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *postOrder(struct TreeNode *root, int *arr, int *size) {
    if (root == NULL) return NULL;
    if (root->left != NULL) postOrder(root->left, arr, size);
    if (root->right != NULL) postOrder(root->right, arr, size);
    arr[(*size)++] = root->val;
    return root;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    int *arr = (int *) malloc(sizeof(int) * 100);
    int size = 0;

    postOrder(root, arr, &size);

    *returnSize = size;
    return arr;
}

// c++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack < TreeNode * > stack_node;
        if (root) stack_node.push(root);
        else return {};
        TreeNode *curr;
        while (!stack_node.empty()) {
            curr = stack_node.top();
            stack_node.pop();
            if (curr) {
                stack_node.push(curr);
                stack_node.push(nullptr);
                if (curr->right) stack_node.push(curr->right);
                if (curr->left) stack_node.push(curr->left);
            } else {
                res.push_back(stack_node.top()->val);
                stack_node.pop();
            }
        }
        return res;
    }
};