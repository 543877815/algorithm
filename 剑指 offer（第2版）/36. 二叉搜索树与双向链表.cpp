/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

// 中序遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
private:
    vector<Node *> record;

    void inorder(Node *root) {
        if (root->left) inorder(root->left);
        if (root) record.push_back(root);
        if (root->right) inorder(root->right);
    }

public:
    Node *treeToDoublyList(Node *root) {
        if (!root) return root;
        inorder(root);
        int n = record.size();
        while (root->left) root = root->left;
        for (int i = 0; i < n; i++) {
            int next = i + 1 != n ? i + 1 : 0;
            int pre = i - 1 != -1 ? i - 1 : n - 1;
            record[i]->left = record[pre];
            record[i]->right = record[next];
        }
        return root;
    }
};