/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    string _Serialize(TreeNode *root) {
        if (!root) return "#";
        return to_string(root->val) + " " + _Serialize(root->left) + " " + _Serialize(root->right);
    }

    char* Serialize(TreeNode *root) {
        string str = _Serialize(root);
        char* res = new char[str.size() + 1];
        res = strcpy(res, str.c_str());
        return res;
    }

    TreeNode* _Deserialize(istringstream &ss) {
        string tmp;
        ss >> tmp;
        if (tmp == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(tmp));
        node->left = _Deserialize(ss);
        node->right = _Deserialize(ss);
        return node;
    }

    TreeNode* Deserialize(char *str) {
        string data = str;
        istringstream ss(data);
        TreeNode* res = _Deserialize(ss);
        return res;
    }
};