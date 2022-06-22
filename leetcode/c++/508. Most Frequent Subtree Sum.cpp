
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

// 前序遍历+哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    unordered_map<int, int> record;

    int addSubTreeSum(TreeNode *root) {
        if (!root) return 0;
        int sum = root->val;
        if (root->left) sum += addSubTreeSum(root->left);
        if (root->right) sum += addSubTreeSum(root->right);

        record[sum]++;

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        addSubTreeSum(root);
        int maxSum = 0;
        for (auto &[key, val]: record) {
            maxSum = max(maxSum, val);
        }

        for (auto &[key, val]: record) {
            if (val == maxSum) res.push_back(key);
        }

        return res;
    }
};