/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 存储父节点
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || !p || !q) return NULL;
        vector < TreeNode * > p_r;
        vector < TreeNode * > q_r;

        TreeNode *curr = root;
        while (curr->val != p->val) {
            p_r.push_back(curr);
            if (curr->val > p->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        p_r.push_back(p);

        curr = root;
        while (curr->val != q->val) {
            q_r.push_back(curr);
            if (curr->val > q->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        q_r.push_back(q);

        unordered_map<int, int> record;
        for (int i = p_r.size() - 1; i >= 0; i--) {
            record[p_r[i]->val]++;
        }

        for (int i = q_r.size() - 1; i >= 0; i--) {
            record[q_r[i]->val]--;
            if (record[q_r[i]->val] == 0) return q_r[i];
        }

        return NULL;
    }
};

// 使用递归
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return NULL;

        if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};

// 不使用递归
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *node = root;
        while (node) {
            if (node->val < p->val && node->val < q->val) {
                node = node->right;
            } else if (node->val > p->val && node->val > q->val) {
                node = node->left;
            } else {
                return node;
            }
        }
        return NULL;
    }
};