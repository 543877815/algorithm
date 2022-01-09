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
class Codec {
public:
    void levelOrder(TreeNode* root, string& res) {
        if (!root) return;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr) {
                q.push(curr->left);
                q.push(curr->right);
                res += to_string(curr->val) + ",";
            } else {
                res += "$,";
            }
        }
    }

    int getData(string_view data, int &index) {
        int n = data.size();
        int sum = 0;
        while(index < n && isdigit(data[index])) {
            sum = sum * 10 + data[index] - '0';
            index++;
        }
        return sum;
    }

    TreeNode* getNode(string_view data, int &index) {
        TreeNode* node = nullptr;
        int n = data.size();
        while (index < n && data[index] == ',') index++;
        if (index >= data.size() || data[index] == '$') {
            index++;
            return node;
        }
        if (data[index] == '-') {
            index++;
            return new TreeNode(-getData(data, index));
        }
        return new TreeNode(getData(data, index));
    }

    TreeNode* deLevelOrder(string_view data) {
        int index = 0;
        int n = data.size();
        queue<TreeNode *> q;
        TreeNode* root = getNode(data, index);
        q.push(root);
        while(!q.empty() && index < n) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr) {
                TreeNode* left = getNode(data, index);
                curr->left = left;
                q.push(left);
                TreeNode* right = getNode(data, index);
                curr->right = right;
                q.push(right);
            }
        }
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        levelOrder(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
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