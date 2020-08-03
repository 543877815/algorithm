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
// 空间复杂度：O(logn)
class Solution {
private:
    vector<int> nums;
public:
    int sumNumbers(TreeNode* root) {
        int init = 0;
        getNumbers(root, init);
        int res = 0;
        for (int num : nums) res += num;
        return res;
    }

    void getNumbers(TreeNode* root, int &num) {
        if (!root) return;
        num = num * 10 + root->val;
        if (!root->left && !root->right) {
            nums.push_back(num);
        }
        getNumbers(root->left, num);
        getNumbers(root->right, num);
        num /= 10;
    }
};