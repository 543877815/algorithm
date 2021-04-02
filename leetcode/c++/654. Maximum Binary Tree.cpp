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
// 递归
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    int n;

    TreeNode *construct(vector<int> &nums, int left, int right) {
        if (right < left) return nullptr;
        int i = left, j = right;
        while (i != j && i >= 0 && j < n) {
            if (nums[i] < nums[j]) i++;
            else j--;
        }
        TreeNode *root = new TreeNode(nums[i]);
        root->left = construct(nums, left, i - 1);
        root->right = construct(nums, j + 1, right);
        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        n = nums.size();
        if (n == 0) return nullptr;
        return construct(nums, 0, n - 1);
    }
};
