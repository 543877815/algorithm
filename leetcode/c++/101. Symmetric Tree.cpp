/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror(struct TreeNode *t1, struct TreeNode *t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode *root) {
    return isMirror(root, root);
}


// c++
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
    bool leftEqualRight(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if ((!left && right) || (left && !right)) return false;
        if (left->val == right->val) {
            return leftEqualRight(left->left, right->right) && leftEqualRight(left->right, right->left);
        } else {
            return false;
        }
    }

    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return leftEqualRight(root->left, root->right);
    }
};


// 非递归
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode *>s;
        s.push(root->left);
        s.push(root->right);

        while(!s.empty()) {
            TreeNode* right = s.top();
            s.pop();
            TreeNode* left = s.top();
            s.pop();

            if (!left && !right) continue;
            if ((!left || !right) || (left->val != right->val)) return false;

            s.push(left->left);
            s.push(right->right);

            s.push(right->left);
            s.push(left->right);
        }

        return true;
    }
};