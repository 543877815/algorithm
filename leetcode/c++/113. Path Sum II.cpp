/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // 使用拷贝
 // 时间复杂度：O(n)
 // 空间复杂度：O(n)
 class Solution {
 private:
     vector<vector<int>> res;

 public:
     vector<vector<int>> pathSum(TreeNode* root, int sum) {
         if (!root) return res;
         vector<int> route;
         getPathSum(root, sum, route);
         return res;
     }

     void getPathSum(TreeNode* root, int sum, vector<int> route) {
         if (!root) return;
         route.push_back(root->val);
         if (sum-root->val == 0 && !root->left && !root->right) {
             res.push_back(route);
             return;
         }
         getPathSum(root->left, sum-root->val, route);
         getPathSum(root->right, sum-root->val, route);
     }
 };

 // 使用引用
 // 时间复杂度：O(n)
 // 空间复杂度：O(n)
 class Solution {
 private:
     vector<vector<int>> res;

 public:
     vector<vector<int>> pathSum(TreeNode* root, int sum) {
         vector<int> route;
         getPathSum(root, sum, route);
         return res;
     }

     void getPathSum(TreeNode* root, int sum, vector<int> &route) {
         if (!root) return;
         route.push_back(root->val);
         if (sum-root->val == 0 && !root->left && !root->right) res.push_back(route);
         getPathSum(root->left, sum-root->val, route);
         getPathSum(root->right, sum-root->val, route);
         route.pop_back();
     }
 };
