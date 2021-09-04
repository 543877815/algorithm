/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
// 遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    Node *insert(Node *head, int insertVal) {
        Node *insertNode = new Node(insertVal);
        if (!head) {

            insertNode->next = insertNode;
            return insertNode;
        }
        Node *curr = head;
        Node *MAX_node = new Node(INT_MIN);
        bool isInsert = false;
        do {
            if (MAX_node->val <= curr->val) MAX_node = curr;
            if (insertVal >= curr->val && insertVal <= curr->next->val) {
                insertNode->next = curr->next;
                curr->next = insertNode;
                isInsert = true;
                break;
            } else {
                curr = curr->next;
            }
        } while (curr != head);
        if (!isInsert) {
            insertNode->next = MAX_node->next;
            MAX_node->next = insertNode;
        }
        return head;
    }
};