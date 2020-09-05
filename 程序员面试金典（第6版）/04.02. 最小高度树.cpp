/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 二分法
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return NULL;
        return createAVLTree(nums, 0, n);
    }

    TreeNode *createAVLTree(vector<int> &nums, int left, int right) {
        if (left == right) return NULL;
        int middle = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[middle]);
        root->left = createAVLTree(nums, left, middle);
        root->right = createAVLTree(nums, middle + 1, right);
        return root;
    }
};
