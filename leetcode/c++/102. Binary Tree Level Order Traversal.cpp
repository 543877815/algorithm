/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MaxSize 760

void LevelOrder(struct TreeNode *TreeRoot, int **ans, int level, int *index) {
    if (TreeRoot != NULL) {
        ans[level][index[level]] = TreeRoot->val;
        index[level]++;
    }

    if (TreeRoot->left != NULL) {
        LevelOrder(TreeRoot->left, ans, level + 1, index);
    }

    if (TreeRoot->right != NULL) {
        LevelOrder(TreeRoot->right, ans, level + 1, index);
    }
}


int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return root;
    }
    int num = MaxSize;
    int **ans = (int **) malloc(sizeof(int *) * num);
    for (int i = 0; i < num; i++) {
        ans[i] = (int *) malloc(sizeof(int) * num);
    }

    int size = 0;
    int *index = (int *) malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++) {
        index[i] = 0;
    }
    LevelOrder(root, ans, 0, index);

    for (int i = 0; i < num; i++) {
        if (index[i] == 0) {
            size = i;
            break;
        }
    }

    *returnSize = size;
    *returnColumnSizes = (int *) malloc(sizeof(int) * (size));
    for (int i = 0; i < size; i++) {
        (*returnColumnSizes)[i] = index[i];
    }
    return ans;
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
    vector <vector<int>> levelOrder(TreeNode *root) {
        vector <vector<int>> res;
        if (!root) return res;
        queue <pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode *node = q.front().first;
            int level = q.front().second;
            q.pop();
            if (level == res.size())
                res.push_back(vector<int>());
            res[level].push_back(node->val);
            if (node->left) q.push(make_pair(node->left, level + 1));
            if (node->right) q.push(make_pair(node->right, level + 1));
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> tmp = {root->val};
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            tmp.clear();
            for (int i = 0; i < size; i++) {
                TreeNode *curr = q.front();
                q.pop();
                tmp.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};