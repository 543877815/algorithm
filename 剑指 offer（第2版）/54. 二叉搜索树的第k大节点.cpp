/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 中序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int kthLargest(TreeNode *root, int k) {
        stack < TreeNode * > stack_node;
        TreeNode *curr = root;
        stack_node.push(curr);
        vector<int> res;
        while (!stack_node.empty()) {
            curr = stack_node.top();
            stack_node.pop();
            if (curr) {
                if (curr->right) stack_node.push(curr->right);
                stack_node.push(curr);
                stack_node.push(nullptr);
                if (curr->left) stack_node.push(curr->left);
            } else {
                res.push_back(stack_node.top()->val);
                stack_node.pop();
            }
        }
        return res[res.size() - k];
    }
};