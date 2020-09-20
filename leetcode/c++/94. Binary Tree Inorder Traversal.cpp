/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode *inOrder(struct TreeNode *root, int *arr, int *size) {
    if (root == NULL) return NULL;
    if (root->left != NULL) inOrder(root->left, arr, size);
    arr[(*size)++] = root->val;
    if (root->right != NULL) inOrder(root->right, arr, size);
    return root;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    int *arr = (int *) malloc(sizeof(int) * 100);
    int size = 0;

    inOrder(root, arr, &size);

    *returnSize = size;
    return arr;
}


// c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return {};
        TreeNode *curr = root;
        stack < TreeNode * > stack_node;
        while (curr || !stack_node.empty()) {
            while (curr) {
                stack_node.push(curr);
                curr = curr->left;
            }
            curr = stack_node.top();
            stack_node.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
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
                stack_node.push(curr);
                stack_node.push(nullptr);
                if (curr->left) stack_node.push(curr->left);
            } else {
                res.push_back(stack_node.top()->val);
                stack_node.pop();
            }
        }
        return res;
    }
};