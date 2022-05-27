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
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    TreeNode *build(vector<int> &preorder, int start, int end) {
        int n = preorder.size();
        if (start > n || start > end) return nullptr;
        int index = start + 1;
        for (; index <= end; index++) {
            if (preorder[index] > preorder[start]) {
                break;
            }
        }
        TreeNode *node = new TreeNode(preorder[start]);
        node->left = build(preorder, start + 1, index - 1);
        node->right = build(preorder, index, end);

        return node;

    }

    TreeNode *bstFromPreorder(vector<int> &preorder) {
        int n = preorder.size();
        return build(preorder, 0, n - 1);
    }
};

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
// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        stack < TreeNode * > sk;
        int n = preorder.size();
        if (n == 0) return nullptr;
        TreeNode *res = new TreeNode(preorder[0]);
        sk.push(res);
        for (int i = 1; i < n; i++) {
            TreeNode *node = sk.top();
            TreeNode *curr = new TreeNode(preorder[i]);

            while (!sk.empty() && sk.top()->val < curr->val) {
                node = sk.top();
                sk.pop();
            }

            if (node->val < curr->val) node->right = curr;
            else node->left = curr;

            sk.push(curr);
        }
        return res;
    }
};