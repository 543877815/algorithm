/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 时间复杂度：O(min(m,n))
// 空间复杂度：O(min(m,n))
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
         TreeNode *T;
        if (t1 && t2) {
            T = new TreeNode(t1->val + t2->val);
            T->left = mergeTrees(t1->left, t2->left);
            T->right = mergeTrees(t1->right, t2->right);
        }
        if (t1 && !t2) {
            T = new TreeNode(t1->val);
            T->left = mergeTrees(t1->left, t2);
            T->right = mergeTrees(t1->right, t2);
        }
        if (!t1 && t2) {
            T = new TreeNode(t2->val);
            T->left = mergeTrees(t1, t2->left);
            T->right = mergeTrees(t1, t2->right);
        }
        if (!t1 && !t2) {
            T = NULL;
        }
        return T;
    }
};


// 时间复杂度：O(min(m,n))
// 空间复杂度：O(min(m,n))
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        auto merged = new TreeNode(t1->val + t2->val);
        merged->left = mergeTrees(t1->left, t2->left);
        merged->right = mergeTrees(t1->right, t2->right);
        return merged;
    }
};