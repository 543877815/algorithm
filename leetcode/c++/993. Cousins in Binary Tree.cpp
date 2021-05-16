/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *findParent(struct TreeNode *root, struct TreeNode *parent, int val, int *index) {
    if (root == NULL) return NULL;
    if (root->val == val) return parent;

    struct TreeNode *parentTmp = NULL;
    if (root->left != NULL) {
        (*index)++;
        parentTmp = findParent(root->left, root, val, index);
        if (parentTmp != NULL) return parentTmp;
        (*index)--;
    }

    if (root->right != NULL) {
        (*index)++;
        parentTmp = findParent(root->right, root, val, index);
        if (parentTmp != NULL) return parentTmp;
        (*index)--;
    }

    return NULL;
}

bool isCousins(struct TreeNode *root, int x, int y) {
    if (root == NULL) return false;
    int depth1 = 0, depth2 = 0;
    struct TreeNode *parent1 = findParent(root, NULL, x, &depth1);
    struct TreeNode *parent2 = findParent(root, NULL, y, &depth2);
    if (depth1 == depth2 && parent1 != parent2) return true;
    else return false;
}

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
// 层次遍历
// 时间复杂度：O(n）
// 空间复杂度：O(logn)
class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        queue <pair<TreeNode *, TreeNode *>> q; // node, parent
        q.push(make_pair(root, nullptr));
        while (!q.empty()) {
            int size = q.size();
            bool findX = false, findY = false;
            TreeNode *parentX = NULL;
            TreeNode *parentY = NULL;
            for (int i = 0; i < size; i++) {
                auto[curr, parent] = q.front();
                q.pop();
                if (x == curr->val) {
                    findX = true;
                    parentX = parent;
                }
                if (y == curr->val) {
                    findY = true;
                    parentY = parent;
                }
                if (curr->left) q.push(make_pair(curr->left, curr));
                if (curr->right) q.push(make_pair(curr->right, curr));
            }
            if ((!findX && findY) || (findX && !findY)) return false;
            if (findX && findY) {
                if (parentX != parentY) return true;
                else return false;
            }
        }
        return false;
    }
};