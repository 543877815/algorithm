/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 时间复杂度：O(n)
// 空间复杂度：O(h)
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return insertNode(nums, 0, nums.size() - 1);
    }

    TreeNode *insertNode(vector<int> &nums, int left, int right) {
        if (right < left) return NULL;
        int middle = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[middle]);
        root->left = insertNode(nums, left, middle - 1);
        root->right = insertNode(nums, middle + 1, right);
        return root;
    }
};