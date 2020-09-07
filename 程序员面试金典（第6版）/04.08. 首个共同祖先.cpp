/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 剑指 offer（第2版）：
// 存储路径
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool GetNodePath(TreeNode *root, TreeNode *p, list<TreeNode *> &path) {
        if (!root) return false;
        path.push_back(root);
        if (root == p) return true;
        bool found = false;
        found = GetNodePath(root->left, p, path) || GetNodePath(root->right, p, path);
        if (!found) path.pop_back();
        return found;
    }

    TreeNode *GetLastCommonNode(const list<TreeNode *> &path1, const list<TreeNode *> &path2) {
        list<TreeNode *>::const_iterator iter1 = path1.begin();
        list<TreeNode *>::const_iterator iter2 = path2.begin();
        TreeNode *same = nullptr;
        while (iter1 != path1.end() && iter2 != path2.end()) {
            if (*iter1 == *iter2) same = *iter1;
            iter1++;
            iter2++;
        }
        return same;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || !p || !q) return NULL;
        list < TreeNode * > path1;
        GetNodePath(root, p, path1);

        list < TreeNode * > path2;
        GetNodePath(root, q, path2);

        return GetLastCommonNode(path1, path2);
    }
};

// 存储父节点
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    unordered_map<int, TreeNode *> fa;
    unordered_map<int, bool> vis;

    void dfs(TreeNode *root) {
        if (root->left != nullptr) {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr) {
            fa[root->right->val] = root;
            dfs(root->right);
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        fa[root->val] = nullptr;
        dfs(root);
        while (p != nullptr) {
            vis[p->val] = true;
            p = fa[p->val];
        }
        while (q != nullptr) {
            if (vis[q->val]) return q;
            q = fa[q->val];
        }
        return nullptr;
    }
};

// 递归
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    TreeNode *ans;

    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) { // p和q存在于左右子树，或者该节点
            ans = root;
        }
        return lson || rson || (root->val == p->val || root->val == q->val);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }
};
