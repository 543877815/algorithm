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
// 中序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    void recoverTree(TreeNode *root) {
        // 中序遍历
        stack < TreeNode * > s;
        if (root) s.push(root);
        else return;
        TreeNode *curr;
        vector < TreeNode * > record;
        while (!s.empty()) {
            curr = s.top();
            s.pop();
            if (curr) {
                if (curr->right) s.push(curr->right);
                s.push(curr);
                s.push(nullptr);
                if (curr->left) s.push(curr->left);
            } else {
                record.push_back(s.top());
                s.pop();
            }
        }

        // 寻找逆序队
        int a = -1, b = -1;
        for (int i = 0; i < record.size() - 1; i++) {
            if (record[i + 1]->val < record[i]->val) {
                b = i + 1;
                if (a == -1) a = i;
                else break;
            }
        }

        // 交换逆序对
        int tmp = record[a]->val;
        record[a]->val = record[b]->val;
        record[b]->val = tmp;
    }
};