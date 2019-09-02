/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB) return NULL;
    struct ListNode *tail = headA;
    while(tail->next) {
        tail = tail -> next;
    }
    tail->next = headB;
    struct ListNode *circle = tail;
    
    while(circle->next) {
        circle = circle -> next;
        if (circle == tail) { // 如果有环
            struct ListNode * slow = headA;
            struct ListNode * fast = headA;
            do {// 找相遇点
                slow = slow -> next;
                fast = fast -> next -> next;
            } while(slow != fast);
            // 再追一次...
            slow = headA;
            while(slow != fast) { 
                slow = slow -> next;
                fast = fast -> next;
            }
            tail -> next = NULL;
            return slow;
        }
    }
    tail -> next = NULL;
    return NULL;
}