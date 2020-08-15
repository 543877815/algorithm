/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
private:
    void cloneNodes(Node *head) {
        while (head) {
            Node *cloneNode = new Node(head->val);
            cloneNode->next = head->next;
            head->next = cloneNode;
            head = cloneNode->next;
        }
    }

    void connectSiblingNodes(Node *head) {
        while (head) {
            Node *cloneNode = head->next;
            if (head->random) cloneNode->random = head->random->next;
            head = cloneNode->next;
        }
    }

    Node *reconnectNodes(Node *head) {
        if (!head) return head;
        Node *cloneHead = head->next;
        Node *curr = head;
        Node *currClone = head->next;

        while (curr) {
            curr->next = curr->next->next;
            curr = curr->next;
            if (currClone && currClone->next) {
                currClone->next = currClone->next->next;
                currClone = currClone->next;
            }
        }

        return cloneHead;
    }

public:
    Node *copyRandomList(Node *head) {
        cloneNodes(head);
        connectSiblingNodes(head);
        return reconnectNodes(head);
    }
};