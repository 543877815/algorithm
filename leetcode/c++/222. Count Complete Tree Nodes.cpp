/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 线性搜索
// 时间复杂度：O(n)
// 空间复杂度：O(d) = O(logN)
class Solution {
public:
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// 二分搜索
// 时间复杂度：O((logn)^2)
// 空间复杂度：O(1)
class Solution {
public:
    int countNodes(TreeNode *root) {
        if (root == NULL)
            return 0;

        //getDepth求出子树高度
        int lDepth = getDepth(root->left);
        int rDepth = getDepth(root->right);

        if (lDepth == rDepth) {  //左子树为满二叉树，右子树继续递归
            return pow(2, lDepth) + countNodes(root->right);
        } else { //左子树继续递归，右子树为满二叉树
            return pow(2, rDepth) + countNodes(root->left);
        }
    }

private:
    int getDepth(TreeNode *root) {
        int Depth = 0;
        while (root) {
            Depth += 1;
            root = root->left;
        }
        return Depth;
    }
};