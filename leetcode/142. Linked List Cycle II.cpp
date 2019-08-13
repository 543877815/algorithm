/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;
    struct ListNode *p = head;
    struct ListNode *q = head->next;
    while(q&&q->next){
        p = p->next;
        q = q->next->next;
        if(q == NULL) return NULL;
        if(p == q) { // 判断有环
            struct ListNode * r = head;
            while(true) {
                q=q->next;
                if(p == q) return p; // 自环
                while(q != p){
                    if (r == q || r == p) {
                       return r;
                    }
                    q=q->next;
                }
                r=r->next;
            }
        };
    }
    return NULL;
}