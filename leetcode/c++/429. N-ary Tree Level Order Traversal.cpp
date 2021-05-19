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
// 层次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector <vector<int>> levelOrder(Node *root) {
        queue < Node * > q;
        vector <vector<int>> res;
        if (!root) return res;
        vector<int> tmp = {root->val};
        res.push_back(tmp);
        for (auto child : root->children) {
            q.push(child);
        }
        while (!q.empty()) {
            int size = q.size();
            tmp.clear();
            for (int i = 0; i < size; i++) {
                Node *curr = q.front();
                q.pop();
                tmp.push_back(curr->val);
                for (auto child: curr->children) {
                    q.push(child);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};