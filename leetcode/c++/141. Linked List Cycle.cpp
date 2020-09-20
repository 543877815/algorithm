/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    int pos = 0;
    struct ListNode *p = head;
    if (p == NULL) return false;
    struct ListNode *q = head->next;
    while(q&&q->next){
        p = p->next;
        q = q->next->next;
        pos++;
        if(q == NULL) return false;
        if(p->val == q->val) return true;
    }
    return false;
}