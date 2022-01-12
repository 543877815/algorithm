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

// 时间复杂度：O(n+logn)
// 空间复杂度：O(n)
class CBTInserter {
public:
    TreeNode *root;
    int num = 0;

    void preorder(TreeNode *root) {
        if (!root) return;
        num++;
        preorder(root->left);
        preorder(root->right);
    }

    CBTInserter(TreeNode *root) {
        this->root = root;
        preorder(this->root);
    }

    int insert(int val) {
        num++;
        TreeNode *node = new TreeNode(val);
        vector<int> record;
        int tmp_num = num;
        while (tmp_num > 1) {
            record.push_back(tmp_num % 2);
            tmp_num /= 2;
        }
        int n = record.size();
        TreeNode *tmp = this->root;

        for (int i = n - 1; i >= 0; i--) {
            if (i != 0) {
                tmp = record[i] ? tmp->right : tmp->left;
            } else {
                if (record[i] == 0) {
                    tmp->left = node;
                } else {
                    tmp->right = node;
                }
            }
        }

        return tmp->val;
    }

    TreeNode *get_root() {
        return this->root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */