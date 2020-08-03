/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size()) return NULL;
        TreeNode *head = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        return head;
    }

    TreeNode *build(vector<int> &preorder, int s1, int e1, vector<int> &inorder, int s2, int e2) {
        TreeNode *root = new TreeNode(preorder[s1]);
        int rootIndex;
        for (int i = s2; i < inorder.size(); i++) {
            if (preorder[s1] == inorder[i]) {
                rootIndex = i;
                break;
            }
        }

        // 如果有左右两个子树, 则rootIndex != s2 && rootIndex != e2,
        // 如果只有左子树, 则 rootindex == e2
        // 如果只有右子树, 则 rootIndex == s2
        if (rootIndex != s2) {
            // 左子树构建的前序遍历起始于 s1 + 1, 结束于 s1 + (rootIndex - s2)
            // 左子树构建的中序遍历起始于 s2, 结束于 rootIndex - 1
            root->left = build(preorder, s1 + 1, s1 + (rootIndex - s2, inorder, s2, rootIndex - 1);
        }
        if (rootIndex != e2) {
            // 右子树构建的前序遍历起始于 (s1 + (rootIndex - s2)) + 1, 结束于 e1
            // 右子树构建的中序遍历起始于 rootIndex + 1, 结束于 e2
            root->right = build(preorder, s1 + rootIndex - s2 + 1, e1, inorder, rootIndex + 1, e2);
        }

        return root;
    }
};