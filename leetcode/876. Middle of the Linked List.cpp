/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    if (!head || !head->next) return head;
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;

    }
    return slow;
}

