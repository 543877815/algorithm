/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// 层次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    Node *connect(Node *root) {
        if (!root) return root;
        queue <pair<int, Node *>> q;
        int level = 0;
        int currLevel = -1;
        Node *currNode = NULL;
        Node *headNode = NULL;
        q.push(make_pair(0, root));
        while (!q.empty()) {
            level = q.front().first;
            currNode = q.front().second;
            q.pop();
            if (currLevel == level) {
                headNode->next = currNode;
                headNode = headNode->next;
            } else {
                headNode = currNode;
                currLevel = level;
            }
            if (currNode->left) q.push(make_pair(level + 1, currNode->left));
            if (currNode->right) q.push(make_pair(level + 1, currNode->right));
        }
        return root;
    }
};