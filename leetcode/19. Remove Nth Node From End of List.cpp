/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (head == NULL || head->next == NULL) return NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head -> next;
    int count = 0;
    while(fast) {
        fast = fast -> next;
        count ++;
    }
    fast = head -> next;
    while (count > n) {
        fast = fast -> next;
        slow = slow -> next;
        count--;
    }
    if (count == n) {
        slow ->next = fast ->next;
    } else {
        head = head -> next;
    }
    return head;
}

