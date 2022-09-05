// ���������л�
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
class Solution {
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        dfs(root);
        return {repeat.begin(), repeat.end()};
    }

    string dfs(TreeNode *node) {
        if (!node) {
            return "";
        }
        string serial = to_string(node->val) + "(" + dfs(node->left) + ")(" + dfs(node->right) + ")";
        if (auto it = seen.find(serial); it != seen.end()) {
            repeat.insert(it->second);
        } else {
            seen[serial] = node;
        }
        return serial;
    }

private:
    unordered_map<string, TreeNode *> seen;
    unordered_set<TreeNode *> repeat;
};