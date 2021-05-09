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
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        queue < pair < TreeNode * , vector < int>>> q;
        if (!root) return 0;
        int currLevel = 0, level = 0, id = 0, begin = 1;
        q.push(make_pair(root, vector < int > {level, id}));
        int res = 1;
        while (!q.empty()) {
            auto[curr, position] = q.front();
            level = position[0];
            id = position[1];
            if (currLevel != level) {
                currLevel = level;
                begin = id;
            } else res = max(res, id - begin + 1);
            q.pop();
            if (curr->left) q.push(make_pair(curr->left, vector < int > {level + 1, id * 2 - 1 - begin * 2}));
            if (curr->right) q.push(make_pair(curr->right, vector < int > {level + 1, id * 2 - begin * 2}));
        }
        return res;
    }
};

// 不保存高度
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        queue<pair<TreeNode *, int>> q;
        if (!root) return 0;
        int begin = 1;
        q.push(make_pair(root, 0));
        int res = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto[curr, id] = q.front();
                if (i == 0) begin = id;
                q.pop();
                res = max(res, id - begin + 1);
                if (curr->left) q.push(make_pair(curr->left, id * 2 - 1 - begin * 2)); // 防止越界
                if (curr->right) q.push(make_pair(curr->right, id * 2 - begin * 2)); // 防止越界
            }
        }
        return res;
    }
};