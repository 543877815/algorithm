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

// 深度优先遍历
// 时间复杂度：o(h)
// 空间复杂度：O(h)
class Solution {
public:
    int maxDepth(Node *root) {
        if (!root) return 0;
        int n = root->children.size();
        int depth = 1;
        for (int i = 0; i < n; i++) {
            depth = max(depth, maxDepth(root->children[i]) + 1);
        }
        return depth;
    }
};