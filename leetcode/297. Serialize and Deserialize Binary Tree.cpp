/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 层次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Codec {
private:
    void levelOrder(TreeNode *root, string &res) {
        if (!root)
            return;
        queue < TreeNode * > q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            if (curr) {
                q.push(curr->left);
                q.push(curr->right);
                res += to_string(curr->val) + ',';
            } else {
                res += "$,";
            }
        }
    }

    TreeNode *deLevelOrder(string_view data) {
        int number;
        queue < TreeNode * > q;
        getData(data, number);
        TreeNode *root = new TreeNode(number);
        q.push(root);
        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            if (getData(data, number)) {
                curr->left = new TreeNode(number);
                q.push(curr->left);
            }
            if (getData(data, number)) {
                curr->right = new TreeNode(number);
                q.push(curr->right);
            }
        }
        return root;
    }

    bool getData(string_view &data, int &number) {
        int n = data.size();
        int i = 0;
        bool isNumber = true;
        number = 0;
        bool negative = false;
        while (i < n) {
            if (data[i] == '-') {
                negative = true;
                i++;
            } else if (data[i] == '$') {
                isNumber = false;
                i++;
            } else if (data[i] == ',') {
                data = data.substr(i + 1);
                if (negative) number = -number;
                return isNumber;
            } else {
                number = number * 10 + (data[i++] - '0');
            }
        }
        return isNumber;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res;
        levelOrder(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.empty()) return NULL;
        return deLevelOrder(data);
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));