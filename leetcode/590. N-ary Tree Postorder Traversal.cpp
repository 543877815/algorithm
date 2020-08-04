/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// 递归法
// 时间复杂度：O(n)
// 空间复杂度：O(h)
class Solution {
private:
    vector<int> res;
public:
    vector<int> postorder(Node *root) {
        if (!root) return {};
        for (int i = 0; i < root->children.size(); i++) {
            postorder(root->children[i]);
        }
        res.push_back(root->val);
        return res;
    }
};