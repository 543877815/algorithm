/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        ListNode *dummynode = new ListNode();
        dummynode->next = head;
        ListNode *pre = dummynode;
        ListNode *curr = head;
        while (curr) {
            if (curr->val == val) {
                pre->next = curr->next;
                curr = curr->next;
            } else {
                pre = pre->next;
                curr = curr->next;
            }
        }
        head = dummynode->next;
        return head;
    }
};