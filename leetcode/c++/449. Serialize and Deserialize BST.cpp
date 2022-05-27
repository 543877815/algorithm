/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 前序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    TreeNode* _deserialize(istringstream &ss) {
        string tmp;
        ss >> tmp;
        if (tmp == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(tmp));
        node->left = _deserialize(ss);
        node->right = _deserialize(ss);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        TreeNode* res = _deserialize(ss);

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;