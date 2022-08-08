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
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        if (!root) return nullptr;
        queue < TreeNode * > q;
        int level = 1;
        if (depth == level) {
            TreeNode *curr = new TreeNode(val);
            curr->left = root;
            return curr;
        } else {
            q.push(root);
        }
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *curr = q.front();
                q.pop();
                if (level + 1 == depth) {
                    TreeNode *inserted_l = new TreeNode(val);
                    inserted_l->left = curr->left;
                    curr->left = inserted_l;
                    q.push(inserted_l);

                    TreeNode *inserted_r = new TreeNode(val);
                    inserted_r->right = curr->right;
                    curr->right = inserted_r;
                    q.push(inserted_r);

                } else {
                    if (curr->left) q.push(curr->left);
                    if (curr->right) q.push(curr->right);
                }
            }
            level++;
            if (level == depth) return root;
        }
        return root;
    }
};