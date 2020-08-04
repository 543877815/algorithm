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

bool isValidBST(struct TreeNode *root) {
    if (root == NULL) return true;
    int *arr = (int *) malloc(sizeof(int) * 20000);
    int size = 0;

    inOrder(root, arr, &size);

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] >= arr[i + 1]) return false;
    }
    return true;
}


// 中序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
private:
    vector<int> res;

    void inOrder(TreeNode *root) {
        if (root->left) inOrder(root->left);
        res.push_back(root->val);
        if (root->right) inOrder(root->right);
    }

public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        inOrder(root);
        for (int i = 0; i < res.size() - 1; i++) {
            if (res[i] >= res[i + 1]) return false;
        }
        return true;
    }
};

