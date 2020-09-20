/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}


class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL) return;

        if (node->next == NULL) {
            delete node;
            node = NULL;
            return;
        }

        node->val = node->next->val;
        ListNode * delNode = node->next;
        node->next = delNode->next;

        delete delNode;

        return;
    }
};