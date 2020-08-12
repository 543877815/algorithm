/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// 递归, m、n分别为A、B树的节点数
// 时间复杂度：O(mn), 先序遍历树A占用O(m),判断占用O(n)
// 空间复杂度：O(m),当树 AA 和树 BB 都退化为链表时，递归调用深度最大。
class Solution {
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        bool result = false;
        if (A && B) {
            if (A->val == B->val) {
                result = hasSubtree(A, B);
            }
            if (!result) {
                result = isSubStructure(A->left, B);
            }
            if (!result) {
                result = isSubStructure(A->right, B);
            }
        }
        return result;
    }

    bool hasSubtree(TreeNode *A, TreeNode *B) {
        if (!B) return true;
        if (!A) return false;
        if (A->val != B->val) return false;

        return hasSubtree(A->left, B->left) && hasSubtree(A->right, B->right);
    }
};