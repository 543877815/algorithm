/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if (!head|| !head->next) return head;
    struct ListNode *returnHead = head->next;
    struct ListNode *pre = NULL;
    struct ListNode *tmp = NULL;
    while(head && head->next) {
        tmp = head->next;
        head->next = tmp->next;
        tmp->next = head;
        if (pre!=NULL) pre->next = tmp;
        pre = head;
        head = head->next;
        
    }
    return returnHead;
}

// use for 255
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *nextTemp = NULL;
    int count = 0;
    while(head) {
        head = head->next;
        count ++;
    }
    while(count!=0) {
        nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
        count --;
    }
    return prev;
}



// c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *p = dummyHead;
        while(p->next && p->next->next) {
            ListNode *node1 = p->next;
            ListNode *node2 = node1->next;
            ListNode *next = node2->next;

            node2->next = node1;
            node1->next = next;
            p->next = node2;

            p = node1;
        }

        ListNode *retNode = dummyHead->next;
        delete dummyHead;

        return retNode;
    }
};