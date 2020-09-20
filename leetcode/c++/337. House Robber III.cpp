/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b) {
    return a > b ? a : b;
}

void postOrder(struct TreeNode *root) {
    if (root == NULL) return;
    if (root->left != NULL) postOrder(root->left);
    if (root->right != NULL) postOrder(root->right);

    int root_node = root->val;
    int node = 0;
    if (root->left != NULL) {
        node += root->left->val;
        if (root->left->left != NULL) {
            root_node += root->left->left->val;
        }
        if (root->left->right != NULL) {
            root_node += root->left->right->val;
        }
    }
    if (root->right != NULL) {
        node += root->right->val;
        if (root->right->left != NULL) {
            root_node += root->right->left->val;
        }
        if (root->right->right != NULL) {
            root_node += root->right->right->val;
        }
    }
    root->val = max(root_node, node);
}


int rob(struct TreeNode *root) {
    if (root == NULL) return 0;
    postOrder(root);
    return root->val;
}


// c++
// 后序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
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
private:
    unordered_map<TreeNode *, int> select, abandon;
public:
    void DFS(TreeNode *root) {
        if (!root) return;
        DFS(root->left);
        DFS(root->right);
        select[root] = root->val + abandon[root->left] + abandon[root->right];
        abandon[root] = max(select[root->left], abandon[root->left]) + max(select[root->right], abandon[root->right]);
    }

    int rob(TreeNode *root) {
        DFS(root);
        return max(select[root], abandon[root]);
    }
};


// 时间复杂度：O(n)
// 空间复杂度：O(n)
struct SubtreeStatus {
    int selected;
    int notSelected;
};

class Solution {
public:
    SubtreeStatus dfs(TreeNode *o) {
        if (!o) {
            return {0, 0};
        }
        auto l = dfs(o->left);
        auto r = dfs(o->right);
        int selected = o->val + l.notSelected + r.notSelected;
        int notSelected = max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
        return {selected, notSelected};
    }

    int rob(TreeNode *o) {
        auto rootStatus = dfs(o);
        return max(rootStatus.selected, rootStatus.notSelected);
    }
};
