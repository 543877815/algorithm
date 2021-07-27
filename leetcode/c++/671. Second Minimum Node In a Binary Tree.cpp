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
// 深度优先遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    priority_queue<int, vector<int>, less<int>> q;
    unordered_map<int, int> hash;

    void preorder(TreeNode *root) {
        if (!root) return;
        if (q.empty() || hash[root->val] == 0) {
            q.push(root->val);
            hash[root->val]++;
        }
        preorder(root->left);
        preorder(root->right);
        if (q.size() > 2) {
            hash[root->val]--;
            q.pop();
        }
    }

    int findSecondMinimumValue(TreeNode *root) {
        preorder(root);
        if (q.size() < 2) return -1;
        int second = q.top();
        q.pop();
        int first = q.top();
        q.pop();
        return second == first ? -1 : second;
    }
};